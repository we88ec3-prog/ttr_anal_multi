
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d4e50(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091ffa6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_007b6d70(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  iVar3 = 8;
  do {
    FUN_004d8260();
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (DAT_00fb12f4 != 0) {
    FUN_0089120c(DAT_00fb12f4);
  }
  DAT_00fb12f4 = 0;
  _DAT_00fb12f8 = 0;
  _DAT_00fb12fc = 0;
  if (7 < DAT_00fb12ec) {
    FUN_0089120c(DAT_00fb12d8);
  }
  DAT_00fb12ec = 7;
  _DAT_00fb12e8 = 0;
  DAT_00fb12d8 = DAT_00fb12d8 & 0xffff0000;
  _eh_vector_destructor_iterator_(&DAT_00fb1214,0x18,8,FUN_004d7fc0);
  FUN_007b6d70();
  FUN_0089120c(DAT_00fb11fc);
  puVar2 = DAT_00fb11f0;
  DAT_00fb11fc = 0;
  puVar1 = DAT_00fb11ec;
  if (DAT_00fb11ec != (undefined4 *)0x0) {
    for (; puVar1 != puVar2; puVar1 = puVar1 + 7) {
      if (7 < (uint)puVar1[5]) {
        FUN_0089120c(*puVar1);
      }
      puVar1[5] = 7;
      puVar1[4] = 0;
      *(undefined2 *)puVar1 = 0;
    }
    FUN_0089120c(DAT_00fb11ec);
  }
  DAT_00fb11ec = (undefined4 *)0x0;
  DAT_00fb11f0 = (undefined4 *)0x0;
  _DAT_00fb11f4 = 0;
  ExceptionList = local_10;
  return;
}

