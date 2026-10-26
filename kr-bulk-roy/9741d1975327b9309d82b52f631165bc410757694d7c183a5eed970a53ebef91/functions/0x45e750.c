
void FUN_0045e750(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int unaff_EDI;
  int local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00931751;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  (**(code **)(**(int **)(unaff_EDI + 0x248) + 0x1ac))
            (*(undefined4 *)(*(int *)(unaff_EDI + 0x250) + 0x20),
             *(undefined4 *)(*(int *)(unaff_EDI + 0x250) + 0x1c),0,0,
             *(undefined4 *)(unaff_EDI + 0x254),local_14);
  if ((DAT_00f8d9a8 & 1) == 0) {
    DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
    local_8 = 0;
    FUN_00523540();
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00521080(&DAT_00f8d9bc);
    _atexit((_func_4879 *)&LAB_00bccc50);
    local_8 = 0xffffffff;
  }
  iVar1 = *(int *)(unaff_EDI + 0x250);
  local_18 = *(undefined4 *)(iVar1 + 0x20);
  FUN_008438c0(&local_18);
  if (local_1c == DAT_00f8d9b0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(local_1c + 0x10);
  }
  if (iVar1 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (uint)*(byte *)(iVar1 + 0x4c);
  }
  uVar2 = *(uint *)(iVar5 + 0x68);
  if ((int)uVar2 < (int)uVar4) {
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (uint)*(byte *)(iVar1 + 0x4c);
    }
  }
  if (*(int *)(iVar5 + 8) == 0xf) {
    uVar3 = 0xffcccccc;
  }
  else {
    switch(uVar2) {
    case 0:
      uVar3 = 0xffffffff;
      break;
    case 1:
      uVar3 = 0xffffff00;
      break;
    case 2:
      uVar3 = 0xff5aff78;
      break;
    case 3:
      uVar3 = 0xff00bbdd;
      break;
    case 4:
      uVar3 = 0xffe243ff;
      break;
    case 5:
      uVar3 = 0xffb41010;
      break;
    default:
      uVar3 = 0xff6600;
    }
  }
  uVar4 = DAT_00fab100 & 1;
  *(undefined4 *)(*(int *)(unaff_EDI + 0x24c) + 0x154) = uVar3;
  if (uVar4 == 0) {
    DAT_00fab100 = DAT_00fab100 | 1;
    local_8 = 2;
    FUN_0049d6a0();
    _atexit((_func_4879 *)&LAB_00bcce20);
    local_8 = 0xffffffff;
  }
  FUN_00757800(*(undefined4 *)(unaff_EDI + 0x250));
  (**(code **)(**(int **)(unaff_EDI + 0x24c) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

