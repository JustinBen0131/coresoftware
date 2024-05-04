// ----------------------------------------------------------------------------
// 'TrksInJetQABaseFiller.h'
// Derek Anderson
// 04.11.2024
//
// A submodule for the TrksInJetQA F4A module to produce
// QA histograms for tracks and more in jets
// ----------------------------------------------------------------------------

#ifndef TRKSINJETQABASEFILLER_H
#define TRKSINJETQABASEFILLER_H

// submodule definitions
#include "TrksInJetQAHitManager.h"
#include "TrksInJetQAClustManager.h"
#include "TrksInJetQATrkManager.h"
#include "TrksInJetQAJetManager.h"
// module utilties
#include "TrksInJetQAHist.h"
#include "TrksInJetQAConfig.h"

// tracking includes
#include <trackbase/ActsGeometry.h>
#include <trackbase/TrkrHitSetContainer.h>
#include <trackbase/TrkrClusterContainer.h>
#include <trackbase_historic/SvtxTrackMap.h>
// jet includes
#include <jetbase/JetContainer.h>

// phool libraries
#include <phool/phool.h>
#include <phool/getClass.h>
#include <phool/PHCompositeNode.h>

// root includes
#include <TFile.h>

// c++ includes
#include <string>


// TrksInJetQABaseFiller ------------------------------------------------------

class TrksInJetQABaseFiller {

  public:

    // ctor/dtor
    TrksInJetQABaseFiller(const TrksInJetQAConfig& config, TrksInJetQAHist& hist);
    virtual ~TrksInJetQABaseFiller();

    // public methods
    void MakeHistograms(const std::string &label = "");
    void SaveHistograms(TFile* outFile, const std::string &outDirName);
    void GrabHistograms(std::vector<TH1D*>& vecOutHist1D, std::vector<TH2D*>& vecOutHist2D);

    // virtual public methods
    virtual void Fill(PHCompositeNode* topNode) = 0;

  protected:

    // private methods
    void GetNodes(PHCompositeNode* topNode);

    // necessary dst nodes
    //   - FIXME these should be smart pointers!
    ActsGeometry*         m_actsGeom = NULL;
    TrkrHitSetContainer*  m_hitMap   = NULL;
    TrkrClusterContainer* m_clustMap = NULL;
    SvtxTrackMap*         m_trkMap   = NULL;
    JetContainer*         m_jetMap   = NULL;

    // submodules to use
    std::unique_ptr<TrksInJetQAHitManager>   m_hitManager   = NULL;
    std::unique_ptr<TrksInJetQAClustManager> m_clustManager = NULL;
    std::unique_ptr<TrksInJetQATrkManager>   m_trackManager = NULL;
    std::unique_ptr<TrksInJetQAJetManager>   m_jetManager   = NULL;

    // module utilities
    TrksInJetQAConfig m_config;
    TrksInJetQAHist   m_hist;

};  // end TrksInJetQABaseFiller

#endif

// end ------------------------------------------------------------------------