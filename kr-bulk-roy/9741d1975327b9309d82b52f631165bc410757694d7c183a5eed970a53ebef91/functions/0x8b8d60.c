
undefined4 FUN_008b8d60(int param_1,int param_2,undefined1 *param_3,int param_4)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  if ((param_3 != (undefined1 *)0x0) && (param_4 != 0)) {
    *param_3 = 0;
  }
  if (param_1 == 0) {
    return 6;
  }
  if (((*(int *)(param_1 + 0x10) < param_2) || ((*(uint *)(param_1 + 8) & 0x200) == 0)) ||
     (puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x80) + 0x24), puVar2 == (undefined4 *)0xfffffffe
     )) {
    return 6;
  }
  if (puVar2 == (undefined4 *)0x0) {
    pcVar1 = *(code **)(**(int **)(param_1 + 0x60) + 0x20);
    if (pcVar1 != (code *)0x0) {
      puVar2 = (undefined4 *)(*pcVar1)(*(int **)(param_1 + 0x60),"glyph-dict");
    }
    puVar4 = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0xfffffffe;
    }
    *(undefined4 **)(*(int *)(param_1 + 0x80) + 0x24) = puVar4;
    if (puVar2 == (undefined4 *)0x0) {
      return 6;
    }
  }
  if ((code *)*puVar2 == (code *)0x0) {
    return 6;
  }
  uVar3 = (*(code *)*puVar2)(param_1,param_2,param_3,param_4);
  return uVar3;
}

