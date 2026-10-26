
void FUN_007c4100(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  void *_Dst;
  uint uVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0;
  if (*(int *)(param_1 + 0xa8) - *(int *)(param_1 + 0xa4) >> 2 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0xa4) + local_c * 4);
      local_8 = 0;
      if (*(int *)(iVar1 + 0x24) - *(int *)(iVar1 + 0x20) >> 2 != 0) {
        do {
          iVar1 = *(int *)(*(int *)(iVar1 + 0x20) + local_8 * 4);
          uVar3 = 0;
          if (*(int *)(iVar1 + 0x48) - *(int *)(iVar1 + 0x44) >> 2 != 0) {
            do {
              if (*(int *)(*(int *)(iVar1 + 0x44) + uVar3 * 4) != 0) {
                puVar2 = *(undefined4 **)(*(int *)(iVar1 + 0x44) + uVar3 * 4);
                if (puVar2 != (undefined4 *)0x0) {
                  (**(code **)*puVar2)(1);
                }
                *(undefined4 *)(*(int *)(iVar1 + 0x44) + uVar3 * 4) = 0;
              }
              *(undefined4 *)(iVar1 + 0x58) = 0;
              uVar3 = uVar3 + 1;
            } while (uVar3 < (uint)(*(int *)(iVar1 + 0x48) - *(int *)(iVar1 + 0x44) >> 2));
          }
          _Dst = *(void **)(iVar1 + 0x44);
          if (_Dst != *(void **)(iVar1 + 0x48)) {
            FID_conflict__memcpy(_Dst,*(void **)(iVar1 + 0x48),0);
            *(void **)(iVar1 + 0x48) = _Dst;
          }
          iVar1 = *(int *)(*(int *)(param_1 + 0xa4) + local_c * 4);
          local_8 = local_8 + 1;
        } while (local_8 < (uint)(*(int *)(iVar1 + 0x24) - *(int *)(iVar1 + 0x20) >> 2));
      }
      local_c = local_c + 1;
    } while (local_c < (uint)(*(int *)(param_1 + 0xa8) - *(int *)(param_1 + 0xa4) >> 2));
  }
  return;
}

