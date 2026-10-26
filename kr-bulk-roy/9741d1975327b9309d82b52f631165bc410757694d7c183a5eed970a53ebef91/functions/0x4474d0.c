
void FUN_004474d0(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00948078;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  iVar2 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00447539;
    iVar2 = FUN_00745c20();
  }
  if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x60) != 0)) &&
      ((*(uint *)(iVar2 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar2 + 0x60) != 0)) {
    FUN_0074a010(iVar2);
  }
LAB_00447539:
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  FUN_007597b0(0);
  FUN_00449b90(*(undefined4 *)(in_ECX + 0x110));
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 1;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  iVar2 = *(int *)(in_ECX + 0x110);
  iVar6 = *(int *)(DAT_00fab130 + 0x5eac);
  uVar1 = *(int *)(iVar2 + 0x10c) - *(int *)(iVar2 + 0x108) >> 2;
  uVar3 = 0;
  if (uVar1 != 0) {
    puVar4 = *(undefined4 **)(iVar2 + 0x108);
    do {
      if (*(int *)*puVar4 == iVar6) {
        if (uVar3 != 0xffffffff) {
          FUN_00446b30(iVar6);
          uVar5 = *(undefined4 *)(in_ECX + 0x110);
          goto LAB_0044762e;
        }
        break;
      }
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar3 < uVar1);
  }
  FUN_00446b30(0);
  uVar5 = *(undefined4 *)(in_ECX + 0x110);
  iVar6 = 0;
LAB_0044762e:
  FUN_0044a3a0(uVar5,iVar6);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 2;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  iVar2 = FUN_004d43d0();
  (**(code **)(**(int **)(*(int *)(in_ECX + 0x110) + 0x100) + 0x94))(iVar2 < 0x50);
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    puStack_10 = (undefined1 *)0x3;
    FUN_004ffe60();
    _atexit((_func_4879 *)&LAB_00bccf00);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_00501650(9);
  ExceptionList = pvStack_18;
  return;
}

