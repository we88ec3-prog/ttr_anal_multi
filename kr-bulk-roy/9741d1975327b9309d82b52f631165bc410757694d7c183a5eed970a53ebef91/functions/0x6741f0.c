
void FUN_006741f0(void)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091f58e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CShopConsumptionDlg::vftable;
  local_8 = 0;
  if (in_ECX[0x7e] != 0) {
    FUN_0049bf30(uVar2);
    FUN_0089120c(in_ECX[0x7e]);
  }
  in_ECX[0x7e] = 0;
  in_ECX[0x7f] = 0;
  in_ECX[0x80] = 0;
  if (7 < (uint)in_ECX[0x7b]) {
    FUN_0089120c(in_ECX[0x76]);
  }
  in_ECX[0x7b] = 7;
  in_ECX[0x7a] = 0;
  *(undefined2 *)(in_ECX + 0x76) = 0;
  if (in_ECX[0x69] != 0) {
    FUN_0089120c(in_ECX[0x69]);
  }
  in_ECX[0x69] = 0;
  in_ECX[0x6a] = 0;
  in_ECX[0x6b] = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_005540c0(*(undefined4 *)in_ECX[0x66],(undefined4 *)in_ECX[0x66]);
  FUN_0089120c(in_ECX[0x66]);
  piVar1 = (int *)in_ECX[0x62];
  piVar3 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(undefined4 *)(in_ECX[0x62] + 4) = in_ECX[0x62];
  in_ECX[99] = 0;
  if (piVar3 != (int *)in_ECX[0x62]) {
    do {
      piVar1 = (int *)*piVar3;
      FUN_0089120c(piVar3);
      piVar3 = piVar1;
    } while (piVar1 != (int *)in_ECX[0x62]);
  }
  FUN_0089120c(in_ECX[0x62]);
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIWindowClose::vftable;
  FUN_00756590();
  ExceptionList = local_10;
  return;
}

