
void FUN_00663fe0(int param_1)

{
  uint *puVar1;
  void *_Dst;
  int **ppiVar2;
  int **ppiVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *local_c;
  int local_8;
  
  iVar5 = *(int *)(*(int *)(param_1 + 0x144) + 0x24c);
  if (iVar5 != 0) {
    iVar5 = *(int *)(iVar5 + 0xcc);
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(iVar5 + 0xdc);
    }
    if (iVar5 != 0) {
      local_8 = *(int *)(iVar5 + 0x20);
      goto LAB_00664024;
    }
  }
  local_8 = -1;
LAB_00664024:
  if (*(int *)(param_1 + 0x1a0) != local_8) {
    puVar1 = (uint *)(param_1 + 0x14c);
    _Dst = (void *)*puVar1;
    if (_Dst != *(void **)(param_1 + 0x150)) {
      FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0x150),0);
      *(void **)(param_1 + 0x150) = _Dst;
    }
    if (local_8 != -1) {
      iVar5 = *(int *)(*(int *)(param_1 + 0x148) + 0xcc);
      if (iVar5 != 0) {
        FUN_00408920(iVar5,*(undefined4 *)(&DAT_00f8631c + local_8 * 4));
      }
      iVar5 = 0;
      if (0 < *(int *)(&DAT_00f8631c + local_8 * 4)) {
        do {
          iVar4 = *(int *)(*(int *)(param_1 + 0x148) + 0xcc);
          if ((((iVar4 == 0) || (iVar5 < 0)) ||
              (*(int *)(iVar4 + 0xac) - *(int *)(iVar4 + 0xa8) >> 2 <= iVar5)) ||
             (piVar6 = *(int **)(*(int *)(iVar4 + 0xa8) + iVar5 * 4), piVar6 == (int *)0x0)) {
LAB_006640fd:
            piVar6 = (int *)0x0;
          }
          else {
            iVar4 = (**(code **)(*piVar6 + 4))();
            if (iVar4 != 0x12d) {
              MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
              goto LAB_006640fd;
            }
          }
          ppiVar2 = *(int ***)(param_1 + 0x150);
          local_c = piVar6;
          if (&local_c < ppiVar2) {
            ppiVar3 = (int **)*puVar1;
            if (&local_c < ppiVar3) goto LAB_00664138;
            if (ppiVar2 == *(int ***)(param_1 + 0x154)) {
              FUN_004deab0();
            }
            if (*(undefined4 **)(param_1 + 0x150) != (undefined4 *)0x0) {
              **(undefined4 **)(param_1 + 0x150) =
                   *(undefined4 *)(*puVar1 + ((int)&local_c - (int)ppiVar3 >> 2) * 4);
            }
          }
          else {
LAB_00664138:
            if (ppiVar2 == *(int ***)(param_1 + 0x154)) {
              FUN_004deab0();
            }
            if (*(int **)(param_1 + 0x150) != (int *)0x0) {
              **(int **)(param_1 + 0x150) = (int)piVar6;
            }
          }
          *(int *)(param_1 + 0x150) = *(int *)(param_1 + 0x150) + 4;
          iVar5 = iVar5 + 1;
        } while (iVar5 < *(int *)(&DAT_00f8631c + local_8 * 4));
      }
    }
    FUN_00749920(*(undefined4 *)(param_1 + 0x148));
    (**(code **)(**(int **)(param_1 + 0x148) + 200))();
    *(int *)(param_1 + 0x1a0) = local_8;
  }
  FUN_006641a0();
  return;
}

