
void FUN_0087a590(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = gbParticleCircleVolume::vftable;
  FUN_00879050();
  FUN_00878e90();
  *in_ECX = gbParticleVolume::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

