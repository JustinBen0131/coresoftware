#include "MvtxDefs.h"

uint8_t
MvtxDefs::getStaveId(TrkrDefs::hitsetkey key)
{
  TrkrDefs::hitsetkey tmp = (key >> MvtxDefs::kBitShiftStaveId);
  return tmp;
}

uint8_t
MvtxDefs::getStaveId(TrkrDefs::cluskey key)
{
  TrkrDefs::hitsetkey tmp = (key >> TrkrDefs::kBitShiftClusId);
  return getStaveId(tmp);
}

uint8_t
MvtxDefs::getChipId(TrkrDefs::hitsetkey key)
{
  TrkrDefs::hitsetkey tmp = (key >> MvtxDefs::kBitShiftChipId);
  return tmp;
}

uint8_t
MvtxDefs::getChipId(TrkrDefs::cluskey key)
{
  TrkrDefs::hitsetkey tmp = (key >> TrkrDefs::kBitShiftClusId);
  return getChipId(tmp);
}

TrkrDefs::hitsetkey
MvtxDefs::genHitSetKey(const char lyr, const uint8_t stave, const uint8_t chip)
{
  TrkrDefs::hitsetkey key = TrkrDefs::genHitSetKey(TrkrDefs::TrkrId::mvtxId, lyr);
  TrkrDefs::hitsetkey tmp = stave;
  key |= (tmp << MvtxDefs::kBitShiftStaveId);
  tmp = chip;
  key |= (tmp << MvtxDefs::kBitShiftChipId);
  return key;
}

TrkrDefs::cluskey
MvtxDefs::genClusKey(const char lyr, const uint8_t stave, const uint8_t chip, const uint32_t clusid)
{
  TrkrDefs::cluskey tmp = genHitSetKey(lyr, stave, chip);
  TrkrDefs::cluskey key = (tmp << TrkrDefs::kBitShiftClusId);
  key |= clusid;
  return key;
}

TrkrDefs::cluskey
MvtxDefs::genClusKey(const TrkrDefs::hitsetkey hskey, const uint32_t clusid)
{
  TrkrDefs::cluskey tmp = hskey;
  TrkrDefs::cluskey key = (tmp << TrkrDefs::kBitShiftClusId);
  key |= clusid;
  return key;
}
