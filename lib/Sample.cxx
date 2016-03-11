///////////////////////////////////////////////////////////////////////////
//                             Sample.cxx                                //
//=======================================================================//
//                                                                       //
//        Keeps track of the sample information. TTree, xsec, etc.       //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// _______________________Includes_______________________________________//
///////////////////////////////////////////////////////////////////////////

#include "Sample.h"

///////////////////////////////////////////////////////////////////////////
// _______________________Constructor/Destructor_________________________//
///////////////////////////////////////////////////////////////////////////

Sample::Sample() 
{
    lumiWeights = 0;
    xsec = -999; 
    lumi = -999;
}

///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

Sample::Sample(TString ifilename, TString iname)
{
    filename = ifilename;
    name = iname;
    treename = TString("dimuons/tree");
    file = new TFile(filename);
    tree = (TTree*)file->Get(treename);

    lumiWeights = 0;
    xsec = -999; 
    lumi = -999;
    
    setBranchAddresses();
    calculateN();
}

///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

Sample::Sample(TString ifilename, TString iname, TString isampleType)
{
    filename = ifilename;
    name = iname;
    sampleType = isampleType;
    treename = TString("dimuons/tree");
    file = new TFile(filename);
    tree = (TTree*)file->Get(treename);

    lumiWeights = 0;
    xsec = -999; 
    lumi = -999;
    
    setBranchAddresses();
    calculateN();
}

///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

Sample::~Sample() {
  // free pointed to memory!
  if (tree != 0) {
    delete tree;
  }
  if (file !=0) {
    delete file;
  }
  if (lumiWeights !=0) {
    delete lumiWeights;
  }
}

///////////////////////////////////////////////////////////////////////////
// _______________________Other Functions________________________________//
///////////////////////////////////////////////////////////////////////////

void Sample::setBranchAddresses()
{
    tree->SetBranchAddress("recoCandMass", &vars.recoCandMass);
    tree->SetBranchAddress("nPU", &vars.nPU);
    tree->SetBranchAddress("recoCandPt", &vars.recoCandPt);
    tree->SetBranchAddress("vertexInfo", &vars.vertices);
    tree->SetBranchAddress("eventInfo", &vars.eventInfo);
    tree->SetBranchAddress("reco1", &vars.reco1);
    tree->SetBranchAddress("reco2", &vars.reco2);
    tree->SetBranchAddress("genWeight", &vars.genWeight);
    tree->SetBranchAddress("pfJets", &vars.jets);
    tree->SetBranchAddress("met", &vars.met);
    tree->SetBranchAddress("recoCandMassPF", &vars.recoCandMassPF);
    tree->SetBranchAddress("recoCandPtPF", &vars.recoCandPtPF);
    tree->SetBranchAddress("rho", &vars.rho);
}
///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

void Sample::calculateN()
{
// Calculate the number of original events using the meta data tree
// Calculate the weighted number of original events as well
    TTree* metadata = (TTree*)file->Get("dimuons/metadata");
    metadata->Draw("sumEventWeights>>eweights_"+name);
    TH1F* sumEventWeightsHist = (TH1F*) gDirectory->Get("eweights_"+name); 

    // There are many ttrees combined so the histogram has a numEvents entry for each
    // file. The total number is equal to the average number times the total number of entries.
    nOriginalWeighted = sumEventWeightsHist->GetEntries()*sumEventWeightsHist->GetMean();

    metadata->Draw("originalNumEvents>>nevents_"+name);
    TH1F* nEventsHist = (TH1F*) gDirectory->Get("nevents_"+name); 
    nOriginal = nEventsHist->GetEntries()*nEventsHist->GetMean();
    if(metadata !=0) delete metadata;

    N = tree->GetEntries();
}

///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

int Sample::getEntry(int i)
{
    tree->GetEntry(i);
    return i;
}

///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

int Sample::getEntry(int i, TEntryList* list)
{
    int treenum = list->GetEntry(i);
    tree->GetEntry(treenum);
    return treenum;
}
