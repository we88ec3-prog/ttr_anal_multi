
void FUN_00576780(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091fe6b;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = GaCha::CGaChaMgr::vftable;
  local_8 = 3;
  FUN_005751a0(in_ECX[1]);
  FUN_00573c00(in_ECX[2]);
  if (in_ECX[1] != 0) {
    FUN_0089120c(in_ECX[1],uVar3);
  }
  iVar1 = in_ECX[2];
  if (iVar1 != 0) {
    FUN_00576340(iVar1);
    FUN_0089120c(iVar1,uVar3);
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_005540c0(*(undefined4 *)in_ECX[0x47],(undefined4 *)in_ECX[0x47]);
  FUN_0089120c(in_ECX[0x47]);
  piVar2 = (int *)in_ECX[0x41];
  piVar4 = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(undefined4 *)(in_ECX[0x41] + 4) = in_ECX[0x41];
  in_ECX[0x42] = 0;
  if (piVar4 != (int *)in_ECX[0x41]) {
    do {
      piVar2 = (int *)*piVar4;
      FUN_0089120c(piVar4);
      piVar4 = piVar2;
    } while (piVar2 != (int *)in_ECX[0x41]);
  }
  FUN_0089120c(in_ECX[0x41]);
  if (7 < (uint)in_ECX[0x2b]) {
    FUN_0089120c(in_ECX[0x26]);
  }
  in_ECX[0x2b] = 7;
  in_ECX[0x2a] = 0;
  *(undefined2 *)(in_ECX + 0x26) = 0;
  FUN_00571700();
  ExceptionList = local_10;
  return;
}

