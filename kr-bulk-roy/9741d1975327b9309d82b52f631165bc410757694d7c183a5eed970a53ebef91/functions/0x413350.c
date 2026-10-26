
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00413350(void)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined2 local_22;
  undefined1 auStack_20 [4];
  undefined4 *puStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0094599a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_22 = 0xa8;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_22,2);
  }
  FUN_0069ab30();
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    uStack_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    uStack_c = 0xffffffff;
  }
  iVar2 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  if (iVar2 != 0) {
    puStack_1c = (undefined4 *)FUN_00891268(0x18);
    if (puStack_1c == (undefined4 *)0x0) {
      puStack_1c = (undefined4 *)0x0;
    }
    else {
      uVar1 = *(ushort *)(iVar2 + 0x88);
      puStack_1c[1] = 0xffffffff;
      puStack_1c[2] = 0xffffffff;
      puStack_1c[3] = 0;
      puStack_1c[4] = 0xf43b9;
      *puStack_1c = FoxUI::FXUIEventI1::vftable;
      puStack_1c[5] = (uint)uVar1;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      uStack_c = 1;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      uStack_c = 0xffffffff;
    }
    FUN_007b6e80(auStack_20);
  }
  (**(code **)(**(int **)(in_ECX + 0x9c) + 0xd0))();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    uStack_c = 2;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    uStack_c = 0xffffffff;
  }
  FUN_007597b0(0);
  (**(code **)(**(int **)(in_ECX + 0x8c) + 200))();
  *(undefined4 *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0xb0) = 1;
  puVar3 = (undefined4 *)FUN_00891268(0x14);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = FoxUI::FXUIEvent::vftable;
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[3] = 0;
    puVar3[4] = 0xf43e4;
  }
  FUN_004072a0();
  if (*(int *)(in_ECX + 0x60) != 0) {
    FUN_0074a010(in_ECX);
  }
  ExceptionList = local_14;
  return;
}

