//////////////////////////////////////////////////////////////////////////
//                             VarSet.cxx                                //
//=======================================================================//
//                                                                       //
//        Keeps track of the variable information for an event.          //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// _______________________Includes_______________________________________//
///////////////////////////////////////////////////////////////////////////

#include "VarSet.h"

///////////////////////////////////////////////////////////////////////////
// _______________________Constructor/Destructor_________________________//
///////////////////////////////////////////////////////////////////////////

VarSet::VarSet() 
{
    varMap["dimu_pt"]     = &VarSet::dimu_pt;
    varMap["mu0_pt"]      = &VarSet::mu1_pt;
    varMap["mu1_pt"]      = &VarSet::mu2_pt;
    varMap["mu0_eta"]     = &VarSet::mu1_eta;
    varMap["mu1_eta"]     = &VarSet::mu2_eta;
    varMap["mu_res_eta"]  = &VarSet::mu_res_eta;
    
    varMap["jet0_pt"]   = &VarSet::jet0_pt;
    varMap["jet1_pt"]   = &VarSet::jet1_pt;
    varMap["jet0_eta"]  = &VarSet::jet0_eta;
    varMap["jet1_eta"]  = &VarSet::jet1_eta;
    
    varMap["m_jj"]          = &VarSet::m_jj;
    varMap["dEta_jj"]       = &VarSet::dEta_jj;
    varMap["dEta_jj_mumu"]  = &VarSet::dEta_jj_mumu;
    
    varMap["bjet0_pt"]   = &VarSet::bjet0_pt;
    varMap["bjet1_pt"]   = &VarSet::bjet1_pt;
    varMap["bjet0_eta"]  = &VarSet::bjet0_eta;
    varMap["bjet1_eta"]  = &VarSet::bjet1_eta;
    
    varMap["m_bb"]     = &VarSet::m_bb;
    varMap["dEta_bb"]  = &VarSet::dEta_bb;
    
    varMap["N_valid_jets"]           = &VarSet::N_valid_jets;
    varMap["N_valid_bjets"]          = &VarSet::N_valid_bjets;
    varMap["N_valid_extra_muons"]    = &VarSet::N_valid_extra_muons;
    varMap["N_valid_electrons"]      = &VarSet::N_valid_electrons;
    varMap["N_valid_extra_leptons"]  = &VarSet::N_valid_extra_leptons;
    
    varMap["MET"]  = &VarSet::MET;
    
    varMap["extra_muon0_pt"]  = &VarSet::extra_muon0_pt; 
    varMap["extra_muon1_pt"]  = &VarSet::extra_muon1_pt; 
    varMap["extra_muon0_eta"] = &VarSet::extra_muon0_eta; 
    varMap["extra_muon1_eta"] = &VarSet::extra_muon1_eta; 

    varMap["electron0_pt"]  = &VarSet::electron0_pt;  
    varMap["electron1_pt"]  = &VarSet::electron1_pt; 
    varMap["electron0_eta"] = &VarSet::electron0_eta; 
    varMap["electron1_eta"] = &VarSet::electron1_eta; 

    varMap["mT_b_MET"] = &VarSet::mT_b_MET;

    varMap["zep0"]          = &VarSet::zep0;
    varMap["zep1"]          = &VarSet::zep1;
    varMap["phi_star"]      = &VarSet::phi_star;
    varMap["dPhi_jj_mumu"]  = &VarSet::dEta_jj_mumu;
}