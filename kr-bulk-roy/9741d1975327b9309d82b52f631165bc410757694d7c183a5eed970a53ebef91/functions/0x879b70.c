
void FUN_00879b70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = gbParticleConeVolume::vftable;
  FUN_00879050();
  FUN_00879050();
  FUN_00878e90();
  FUN_00878e90();
  *in_ECX = gbParticleVolume::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

