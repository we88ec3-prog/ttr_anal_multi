
void FUN_00768c00(ushort param_1)

{
  uint uVar1;
  ushort ****ppppuVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  ushort ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916868;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  if ((((param_1 != 10) && (param_1 != 0xd)) && ((param_1 < 0x20 || (0x7e < param_1)))) &&
     ((param_1 < 0xe01 || (0xe5b < param_1)))) goto LAB_00768d6d;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (ushort ***)((uint)local_30[0] & 0xffff0000);
  local_8 = 0;
  FUN_00440010(1,0);
  ppppuVar2 = (ushort ****)local_30[0];
  if (local_1c < 8) {
    ppppuVar2 = local_30;
  }
  *(ushort *)ppppuVar2 = param_1;
  iVar3 = FUN_007680b0(local_30);
  if (iVar3 < 1) {
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    goto LAB_00768d6d;
  }
  if (*(uint *)(in_ECX + 0x13c) < (uint)(*(int *)(in_ECX + 0x114) - *(int *)(in_ECX + 0x110) >> 2))
  {
    iVar3 = *(int *)(*(int *)(in_ECX + 0x110) + *(uint *)(in_ECX + 0x13c) * 4);
    uVar4 = FUN_00671e60(uVar1);
    if ((*(uint *)(in_ECX + 0x140) <= *(uint *)(iVar3 + 0x10)) &&
       (iVar3 = FUN_00777340(uVar4,iVar3), 0 < iVar3)) {
      uVar4 = *(undefined4 *)(in_ECX + 0x13c);
LAB_00768d3b:
      FUN_007660d0(in_ECX,&param_1,uVar4);
      FUN_00767a80();
    }
  }
  else {
    iVar3 = FUN_00671e60(uVar1);
    if (((*(int *)(iVar3 + 4) == 0) || (0x5a < (ushort)(param_1 - 0xe01))) || (param_1 < 0xe2f)) {
      uVar4 = *(undefined4 *)(in_ECX + 0x13c);
      goto LAB_00768d3b;
    }
  }
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
LAB_00768d6d:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

