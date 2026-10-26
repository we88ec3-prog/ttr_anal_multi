
void FUN_0055bb50(int param_1)

{
  undefined4 *puVar1;
  void *_Dst;
  int iVar2;
  int *piVar3;
  int local_8;
  
  local_8 = 0x104;
  do {
    iVar2 = *(int *)(param_1 + 0x4d30) * 0x4c;
    piVar3 = *(int **)(iVar2 + 0x3c + param_1);
    puVar1 = (undefined4 *)(iVar2 + 0x3c + param_1);
    if (piVar3 != *(int **)(iVar2 + 0x40 + param_1)) {
      do {
        if ((undefined4 *)*piVar3 != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)*piVar3)(1);
        }
        piVar3 = piVar3 + 1;
      } while (piVar3 != (int *)puVar1[1]);
    }
    _Dst = (void *)*puVar1;
    if (_Dst != (void *)puVar1[1]) {
      FID_conflict__memcpy(_Dst,(void *)puVar1[1],0);
      puVar1[1] = _Dst;
    }
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  *(undefined4 *)(param_1 + 0x4d30) = 0;
  return;
}

