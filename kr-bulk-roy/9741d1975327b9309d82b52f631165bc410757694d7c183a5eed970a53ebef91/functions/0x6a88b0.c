
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006a88b0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xf4);
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 0x141) == '\0') {
      FUN_00757710();
    }
    else {
      FUN_006edb10("Not supported operation");
    }
    *(undefined4 *)(iVar1 + 0x168) = 0;
    *(undefined4 *)(iVar1 + 0x160) = 0;
    *(undefined4 *)(iVar1 + 0x164) = 0;
    *(undefined4 *)(iVar1 + 0x14c) = 0;
    (**(code **)(**(int **)(in_ECX + 0xf4) + 200))();
  }
  FUN_007459c0();
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_006a894e;
    in_ECX = FUN_00745c20();
  }
  if (((in_ECX != 0) && (*(int *)(in_ECX + 0x60) != 0)) &&
     ((*(uint *)(in_ECX + 0x28) >> 0xc & 1) == 0)) {
    FUN_0074a010(in_ECX);
  }
LAB_006a894e:
  if ((_DAT_00fe2ffc & 1) != 0) {
    _DAT_00fe3004 = 1;
    return;
  }
  _DAT_00fe2ffc = _DAT_00fe2ffc | 1;
  _DAT_00fe3000 = 1;
  _DAT_00fe3004 = 0;
  _atexit((_func_4879 *)&DAT_00bcfed0);
  _DAT_00fe3004 = 1;
  return;
}

