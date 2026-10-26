
void FUN_00654e70(int param_1)

{
  uint *puVar1;
  int iVar2;
  void *_Dst;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int local_c;
  int local_8;
  
  if ((*(int *)(param_1 + 0xd4) != -1) && (local_c = 0, 0 < *(int *)(param_1 + 0xd4))) {
    piVar6 = (int *)(param_1 + 0xac);
    do {
      FUN_006544c0(*piVar6,*(undefined1 *)(param_1 + 0xa9));
      iVar2 = *piVar6;
      local_8 = iVar2;
      if ((byte)local_c < *(byte *)(iVar2 + 1)) {
        puVar1 = (uint *)(iVar2 + 0x20);
        *(undefined4 *)(iVar2 + 0xc) = 0;
        _Dst = (void *)*puVar1;
        iVar5 = iVar2;
        if (_Dst != *(void **)(iVar2 + 0x24)) {
          FID_conflict__memcpy(_Dst,*(void **)(iVar2 + 0x24),0);
          *(void **)(iVar2 + 0x24) = _Dst;
          iVar5 = local_8;
        }
        piVar3 = *(int **)(iVar2 + 0x24);
        local_8 = 0;
        if ((&local_8 < piVar3) && (piVar4 = (int *)*puVar1, piVar4 <= &local_8)) {
          if (piVar3 == *(int **)(iVar2 + 0x28)) {
            FUN_004deab0();
          }
          if (*(undefined4 **)(iVar2 + 0x24) != (undefined4 *)0x0) {
            **(undefined4 **)(iVar2 + 0x24) =
                 *(undefined4 *)(*puVar1 + ((int)&local_8 - (int)piVar4 >> 2) * 4);
          }
        }
        else {
          if (piVar3 == *(int **)(iVar2 + 0x28)) {
            FUN_004deab0();
          }
          if (*(undefined4 **)(iVar2 + 0x24) != (undefined4 *)0x0) {
            **(undefined4 **)(iVar2 + 0x24) = 0;
          }
        }
        *(int *)(iVar2 + 0x24) = *(int *)(iVar2 + 0x24) + 4;
        *(byte *)(iVar5 + 0x30) = (byte)local_c;
        *(undefined1 *)(iVar5 + 0x31) = 0;
        *(undefined4 *)(iVar5 + 0x34) = 0;
      }
      local_c = local_c + 1;
      piVar6 = piVar6 + 1;
    } while (local_c < *(int *)(param_1 + 0xd4));
  }
  return;
}

