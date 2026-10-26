
void FUN_0064a790(void)

{
  int *piVar1;
  void *_Dst;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  int *piVar6;
  int *local_24;
  int local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00926ae6;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _Dst = *(void **)(in_ECX + 0x114);
  piVar1 = (int *)(in_ECX + 0x114);
  if (_Dst != *(void **)(in_ECX + 0x118)) {
    FID_conflict__memcpy(_Dst,*(void **)(in_ECX + 0x118),0);
    *(void **)(in_ECX + 0x118) = _Dst;
  }
  if ((DAT_00fb725c & 1) == 0) {
    DAT_00fb725c = DAT_00fb725c | 1;
    local_8 = 0;
    FUN_004a79a0(uVar4);
    _atexit((_func_4879 *)&DAT_00bccf80);
    local_8 = 0xffffffff;
  }
  FUN_004462a0();
  local_8 = 1;
  piVar6 = local_24;
  for (iVar5 = local_20 - (int)local_24 >> 2; iVar5 != 0; iVar5 = iVar5 + -1) {
    if (*(char *)(*piVar6 + 9) == '\0') {
      piVar2 = *(int **)(in_ECX + 0x118);
      if ((piVar6 < piVar2) && (piVar3 = (int *)*piVar1, piVar3 <= piVar6)) {
        if (piVar2 == *(int **)(in_ECX + 0x11c)) {
          FUN_006d6240();
        }
        if (*(undefined4 **)(in_ECX + 0x118) != (undefined4 *)0x0) {
          **(undefined4 **)(in_ECX + 0x118) =
               *(undefined4 *)(*piVar1 + ((int)piVar6 - (int)piVar3 >> 2) * 4);
        }
      }
      else {
        if (piVar2 == *(int **)(in_ECX + 0x11c)) {
          FUN_006d6240();
        }
        if (*(int **)(in_ECX + 0x118) != (int *)0x0) {
          **(int **)(in_ECX + 0x118) = *piVar6;
        }
      }
      *(int *)(in_ECX + 0x118) = *(int *)(in_ECX + 0x118) + 4;
    }
    else {
      FUN_0044a480(piVar1,*piVar1);
    }
    piVar6 = piVar6 + 1;
  }
  if (local_24 != (int *)0x0) {
    FUN_0089120c(local_24);
  }
  ExceptionList = local_10;
  return;
}

