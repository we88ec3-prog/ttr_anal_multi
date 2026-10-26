
uint FUN_00781130(uint param_1)

{
  uint uVar1;
  int *piVar2;
  undefined1 *puVar3;
  int iVar4;
  void *_Dst;
  int iVar5;
  int iVar6;
  int in_ECX;
  size_t _Size;
  
  if (param_1 == 0xffffffff) {
    return 0;
  }
  uVar1 = **(uint **)(in_ECX + 0x24);
  if ((uVar1 != 0) && (piVar2 = *(int **)(in_ECX + 0x34), uVar1 < *piVar2 + uVar1)) {
    *piVar2 = *piVar2 + -1;
    puVar3 = (undefined1 *)**(int **)(in_ECX + 0x24);
    **(int **)(in_ECX + 0x24) = (int)(puVar3 + 1);
    *puVar3 = (char)param_1;
    return param_1 & 0xff;
  }
  if (((*(uint *)(in_ECX + 0x48) & 4) != 0) && ((*(uint *)(in_ECX + 0x48) & 10) == 0)) {
    if (**(int **)(in_ECX + 0x20) == 0) {
      _Size = 0;
    }
    else {
      _Size = (**(int **)(in_ECX + 0x34) - **(int **)(in_ECX + 0x10)) + uVar1;
    }
    iVar4 = (int)_Size / 2;
    if ((int)_Size / 2 < *(int *)(in_ECX + 0x3c)) {
      iVar4 = *(int *)(in_ECX + 0x3c);
    }
    *(undefined4 *)(in_ECX + 0x3c) = 0x20;
    for (; 0 < iVar4; iVar4 = iVar4 / 2) {
      if ((int)_Size <= 0x7fffffff - iVar4) {
        if (iVar4 < 1) {
          return 0xffffffff;
        }
        iVar4 = iVar4 + _Size;
        if (*(code **)(in_ECX + 0x4c) == (code *)0x0) {
          _Dst = (void *)FUN_0087dc3d(iVar4);
        }
        else {
          _Dst = (void *)(**(code **)(in_ECX + 0x4c))();
        }
        if (_Dst == (void *)0x0) {
          return 0xffffffff;
        }
        if (0 < (int)_Size) {
          FID_conflict__memcpy(_Dst,(void *)**(undefined4 **)(in_ECX + 0x10),_Size);
        }
        if ((*(byte *)(in_ECX + 0x48) & 1) != 0) {
          if (*(code **)(in_ECX + 0x50) == (code *)0x0) {
            FUN_00891d3d(**(undefined4 **)(in_ECX + 0x10));
          }
          else {
            (**(code **)(in_ECX + 0x50))(**(undefined4 **)(in_ECX + 0x10));
          }
        }
        *(uint *)(in_ECX + 0x48) = *(uint *)(in_ECX + 0x48) | 1;
        if (_Size == 0) {
          *(void **)(in_ECX + 0x44) = _Dst;
          **(undefined4 **)(in_ECX + 0x14) = _Dst;
          **(undefined4 **)(in_ECX + 0x24) = _Dst;
          **(int **)(in_ECX + 0x34) = iVar4;
          **(undefined4 **)(in_ECX + 0x10) = _Dst;
          **(undefined4 **)(in_ECX + 0x20) = _Dst;
          **(undefined4 **)(in_ECX + 0x30) = 0;
        }
        else {
          *(int *)(in_ECX + 0x44) =
               (int)_Dst + (*(int *)(in_ECX + 0x44) - **(int **)(in_ECX + 0x10));
          iVar6 = **(int **)(in_ECX + 0x10);
          iVar5 = (**(int **)(in_ECX + 0x24) - iVar6) + (int)_Dst;
          **(int **)(in_ECX + 0x14) = (int)_Dst + (**(int **)(in_ECX + 0x14) - iVar6);
          **(int **)(in_ECX + 0x24) = iVar5;
          **(int **)(in_ECX + 0x34) = (int)_Dst + (iVar4 - iVar5);
          iVar4 = **(int **)(in_ECX + 0x24);
          iVar6 = (**(int **)(in_ECX + 0x20) - **(int **)(in_ECX + 0x10)) + (int)_Dst;
          **(int **)(in_ECX + 0x10) = (int)_Dst;
          **(int **)(in_ECX + 0x20) = iVar6;
          **(int **)(in_ECX + 0x30) = (iVar4 - iVar6) + 1;
        }
        **(int **)(in_ECX + 0x34) = **(int **)(in_ECX + 0x34) + -1;
        puVar3 = (undefined1 *)**(int **)(in_ECX + 0x24);
        **(int **)(in_ECX + 0x24) = (int)(puVar3 + 1);
        *puVar3 = (char)param_1;
        return param_1 & 0xff;
      }
    }
  }
  return 0xffffffff;
}

