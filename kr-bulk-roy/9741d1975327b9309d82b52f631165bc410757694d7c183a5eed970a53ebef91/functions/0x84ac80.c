
void FUN_0084ac80(void)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0091144e;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = gbParticleSystem::vftable;
  local_8 = 3;
  if (in_ECX[0x1d] != in_ECX[0x1e]) {
    uVar4 = FUN_0084b880(in_ECX[0x1e]);
    FUN_0084b900(uVar4,in_ECX[0x1e],in_ECX);
    in_ECX[0x1e] = uVar4;
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  puVar2 = (undefined4 *)in_ECX[0x25];
  if (puVar2 != (undefined4 *)0x0) {
    piVar1 = puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)*puVar2)(1,uVar3);
    }
  }
  if (in_ECX[0x21] != 0) {
    FUN_0089120c(in_ECX[0x21]);
  }
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  local_8 = local_8 & 0xffffff00;
  if (in_ECX[0x1d] != 0) {
    FUN_0084b900(in_ECX[0x1d],in_ECX[0x1e],in_ECX);
    FUN_0089120c(in_ECX[0x1d]);
  }
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  local_8 = 0xffffffff;
  *in_ECX = gbObject3d::vftable;
  FUN_00780000();
  ExceptionList = local_10;
  return;
}

