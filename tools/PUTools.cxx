///////////////////////////////////////////////////////////////////////////
//                           PUTools.cxx                                 //
//=======================================================================//
//                                                                       //
//     Make histograms for the StandAloneLumiReweighter, which gives     //
//     us PU weights. But we usually just do this at analyzer level now, //
//     rather than use the stand alone tool to calculate the weight      //
//     at plotting time.                                                 //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

#include <vector>
#include <utility> // pair
#include <map>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>

#include "PUTools.h"
#include "TString.h"
#include "Sample.h"

//////////////////////////////////////////////////////////////////
//---------------------------------------------------------------
//////////////////////////////////////////////////////////////////

void PUTools::savePUHisto(Sample* s, TString savedir)
{
// Save the pileup histogram needed by reweight::lumiReWeighting for a MC sample.

    TH1F* pileuphist = new TH1F("pileup", "pileup", 50, 0, 50);
    for(unsigned int i=0; i<s->N; i++)
    {   
        s->getEntry(i);
        pileuphist->Fill(s->vars.nPU, s->vars.gen_wgt);
    }   

    TFile* savefile = new TFile(savedir+"PUCalib_"+s->name+".root", "RECREATE");
    savefile->cd();
    pileuphist->Write();
    savefile->Close();
    //delete savefile;
}

//////////////////////////////////////////////////////////////////
//---------------------------------------------------------------
//////////////////////////////////////////////////////////////////

void PUTools::makePUHistos(std::map<std::string, Sample*> samples)
{
// Make the pileup histograms for the MC samples. reweight::lumiReWeighting uses these to calculate the
// pileup reweighting weights.

    // Create pileup reweighting histos
    for(auto const &i : samples)
    {
        std::cout << "  +++ Making PU Histo for " << i.second->name << std::endl;
        std::cout << std::endl;

        if(i.second->sampleType.Contains("data")) continue;

        std::cout << "    +++ Saving the histo..."  << std::endl;
        std::cout << std::endl;

        savePUHisto(i.second, "pu_reweight_trees/8_0_X/");
    }
}
