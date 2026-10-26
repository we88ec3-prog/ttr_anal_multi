
void FUN_004261e0(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int unaff_EDI;
  undefined4 local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00941bda;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  FUN_00426390(unaff_EDI);
  iVar3 = 0;
  do {
    if (((uint)*(byte *)(unaff_EDI + 0x10c) & 1 << ((byte)iVar3 & 0x1f)) != 0) break;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(uVar2);
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  local_1c[0] = *(undefined4 *)(DAT_00fab130 + 0x5eac);
  if ((DAT_00fb7324 & 1) == 0) {
    DAT_00fb7324 = DAT_00fb7324 | 1;
    local_c = 1;
    FUN_0081b920();
    _atexit((_func_4879 *)&LAB_00bcd080);
    local_c = 0xffffffff;
  }
  FUN_0081c9e0(local_1c);
  FUN_004266e0(unaff_EDI);
  local_1c[0] = 0;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 2;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  FUN_004d9d20(DAT_00f94308,0xc);
  cVar1 = *(char *)(unaff_EDI + 0x10d);
  FUN_007598b0(0);
  FUN_007598b0(1);
  *(uint *)(*(int *)(unaff_EDI + 0x100) + 0x154) = (-(uint)(cVar1 != '\0') & 0xff01ff00) - 0x10000;
  (**(code **)(**(int **)(unaff_EDI + 0x100) + 200))();
  ExceptionList = local_14;
  return;
}

