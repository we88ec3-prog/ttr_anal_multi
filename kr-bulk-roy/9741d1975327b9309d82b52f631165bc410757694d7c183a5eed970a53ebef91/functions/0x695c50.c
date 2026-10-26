
/* WARNING: Removing unreachable block (ram,0x00695d58) */

void FUN_00695c50(void)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009211e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  if (in_ECX[0x3d] == 0x16) {
    FUN_005adc60();
  }
  else {
    if (in_ECX[0x3d] != 0x24) goto LAB_00695cd4;
    FUN_00695e80(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  }
  FUN_005a9f40(in_ECX + 0x3c);
LAB_00695cd4:
  FUN_0040b670(in_ECX);
  (**(code **)(*(int *)in_ECX[0x3b] + 0x70))(in_ECX[0x3c]);
  iVar1 = in_ECX[0x3c];
  iVar2 = *(int *)(iVar1 + 8);
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -iVar2;
  *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -iVar2;
  iVar2 = *(int *)(iVar1 + 0xc);
  *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + -iVar2;
  *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + -iVar2;
  FUN_00746f70();
  (**(code **)(*(int *)in_ECX[0x3c] + 0xd0))();
  (**(code **)(*(int *)in_ECX[0x3b] + 0xb4))(in_ECX[0x3e]);
  (**(code **)(*in_ECX + 0xb4))(0xda);
  ExceptionList = local_10;
  return;
}

