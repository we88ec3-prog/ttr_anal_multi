
void FUN_004506e0(void)

{
  int *piVar1;
  code *pcVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  int unaff_EDI;
  uint local_5c [4];
  undefined4 local_4c;
  uint local_48;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093427c;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb725c & 1) == 0) {
    DAT_00fb725c = DAT_00fb725c | 1;
    local_8 = 0;
    FUN_004a79a0(local_14);
    _atexit((_func_4879 *)&DAT_00bccf80);
  }
  local_8 = 0xffffffff;
  uVar7 = DAT_00fb7284 - DAT_00fb7280 >> 2;
  uVar3 = 0;
  if (uVar7 != 0) {
    do {
      puVar4 = *(uint **)(DAT_00fb7280 + uVar3 * 4);
      if (*puVar4 == (uint)*(byte *)(unaff_EDI + 600)) goto LAB_00450775;
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar7);
  }
  puVar4 = (uint *)0x0;
LAB_00450775:
  uVar5 = FUN_004a78b0(puVar4);
  local_8 = 1;
  FUN_00757800(uVar5);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  (**(code **)(**(int **)(unaff_EDI + 0x248) + 200))();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 2;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_38 = 0x14c;
  FUN_005740f0(&local_38);
  if (local_34 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar6 = (undefined4 *)(local_34 + 0x10);
  if (7 < *(uint *)(local_34 + 0x24)) {
    puVar6 = (undefined4 *)*puVar6;
  }
  FUN_0040e460(puVar6);
  local_8 = 3;
  if (*(int *)(*(int *)(unaff_EDI + 0x24c) + 0xcc) != 0) {
    FUN_00757800(local_5c);
  }
  local_8 = 0xffffffff;
  if (7 < local_48) {
    FUN_0089120c(local_5c[0]);
  }
  local_5c[0] = local_5c[0] & 0xffff0000;
  piVar1 = *(int **)(unaff_EDI + 0x24c);
  piVar1[0x34] = *(int *)(unaff_EDI + 0x25c);
  local_48 = 7;
  local_4c = 0;
  (**(code **)(*piVar1 + 0x128))();
  (**(code **)(**(int **)(unaff_EDI + 0x24c) + 200))();
  FUN_007597b0(0);
  (**(code **)(**(int **)(unaff_EDI + 0x254) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

