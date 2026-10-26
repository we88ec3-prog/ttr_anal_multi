
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00422a50(void)

{
  uint uVar1;
  char cVar2;
  int in_ECX;
  int iVar3;
  int local_20;
  uint uStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00941c7c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  iVar3 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00422ab8;
    iVar3 = FUN_00745c20();
  }
  if ((((iVar3 != 0) && (*(int *)(iVar3 + 0x60) != 0)) &&
      ((*(uint *)(iVar3 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar3 + 0x60) != 0)) {
    FUN_0074a010(iVar3);
  }
LAB_00422ab8:
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_20 = CONCAT22(local_20._2_2_,0xa8);
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_20,2);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  iVar3 = 0;
  uVar1 = DAT_00f94390 & 1;
  *(undefined1 *)(in_ECX + 0x100) = DAT_00f942d9;
  local_20 = 0;
  if (uVar1 == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  cVar2 = FUN_004d9d20(DAT_00f94308,0xc);
  if (cVar2 != '\0') {
    iVar3 = 2;
  }
  uStack_1c = (uint)*(byte *)(in_ECX + 0x100);
  local_20 = iVar3 + 3;
  FUN_00422e30(&local_20);
  FUN_007597b0(0);
  ExceptionList = local_14;
  return;
}

