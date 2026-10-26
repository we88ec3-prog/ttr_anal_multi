
void FUN_007e0c30(int param_1)

{
  int iVar1;
  void *_Dst;
  int *piVar2;
  int local_c;
  int *local_8;
  
  local_8 = (int *)(param_1 + 0xc);
  local_c = 8;
  do {
    iVar1 = *local_8;
    if (iVar1 != 0) {
      if (*(undefined4 **)(iVar1 + 0x10) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(iVar1 + 0x10))(1);
        *(undefined4 *)(iVar1 + 0x10) = 0;
      }
      if (*(int *)(iVar1 + 0xc) != 0) {
        FUN_0089120c(*(int *)(iVar1 + 0xc));
        *(undefined4 *)(iVar1 + 0xc) = 0;
      }
      if (*(undefined4 **)(iVar1 + 4) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(iVar1 + 4))(1);
        *(undefined4 *)(iVar1 + 4) = 0;
      }
      if (*(int *)(iVar1 + 8) != 0) {
        FUN_007f3c20();
        *(undefined4 *)(iVar1 + 8) = 0;
      }
      iVar1 = *local_8;
      if (iVar1 != 0) {
        if (0xf < *(uint *)(iVar1 + 0x28)) {
          FUN_0089120c(*(undefined4 *)(iVar1 + 0x14));
        }
        *(undefined4 *)(iVar1 + 0x28) = 0xf;
        *(undefined4 *)(iVar1 + 0x24) = 0;
        *(undefined1 *)(iVar1 + 0x14) = 0;
        FUN_0089120c(iVar1);
        *local_8 = 0;
      }
    }
    local_8 = local_8 + 1;
    local_c = local_c + -1;
  } while (local_c != 0);
  piVar2 = *(int **)(param_1 + 0x34);
  if (piVar2 != *(int **)(param_1 + 0x38)) {
    do {
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != *(int **)(param_1 + 0x38));
  }
  _Dst = *(void **)(param_1 + 0x34);
  if (_Dst != *(void **)(param_1 + 0x38)) {
    FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0x38),0);
    *(void **)(param_1 + 0x38) = _Dst;
  }
  return;
}

