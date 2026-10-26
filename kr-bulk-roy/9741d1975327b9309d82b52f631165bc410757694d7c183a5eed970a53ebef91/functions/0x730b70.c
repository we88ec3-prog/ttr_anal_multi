
/* WARNING: Type propagation algorithm not settling */

void FUN_00730b70(void *param_1,char *param_2)

{
  char *_Size;
  char *pcVar1;
  int unaff_ESI;
  char *_Dst;
  undefined **local_10 [3];
  
  _Size = param_2;
  if (((byte)*(undefined4 *)(unaff_ESI + 0x40) & 6) != 6) {
    _Dst = (char *)0x0;
    if ((param_2 != (char *)0x0) && (_Dst = (char *)FUN_00891268(param_2), _Dst == (char *)0x0)) {
      param_2 = (char *)0x0;
      std::exception::exception((exception *)local_10,&param_2);
      local_10[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_10,&DAT_00c857a8);
    }
    FID_conflict__memcpy(_Dst,param_1,(size_t)_Size);
    *(char **)(unaff_ESI + 0x3c) = _Dst + (int)_Size;
    if ((*(byte *)(unaff_ESI + 0x40) & 4) == 0) {
      **(undefined4 **)(unaff_ESI + 0x10) = _Dst;
      **(undefined4 **)(unaff_ESI + 0x20) = _Dst;
      **(size_t **)(unaff_ESI + 0x30) = (size_t)_Size;
    }
    if ((*(uint *)(unaff_ESI + 0x40) & 2) == 0) {
      pcVar1 = _Dst + (int)_Size;
      if ((*(uint *)(unaff_ESI + 0x40) & 0x10) == 0) {
        pcVar1 = _Dst;
      }
      **(undefined4 **)(unaff_ESI + 0x14) = _Dst;
      **(int **)(unaff_ESI + 0x24) = (int)pcVar1;
      **(int **)(unaff_ESI + 0x34) = (int)(_Size + ((int)_Dst - (int)pcVar1));
      if (**(int **)(unaff_ESI + 0x20) == 0) {
        **(undefined4 **)(unaff_ESI + 0x10) = _Dst;
        **(undefined4 **)(unaff_ESI + 0x20) = 0;
        **(undefined4 **)(unaff_ESI + 0x30) = _Dst;
      }
    }
    *(uint *)(unaff_ESI + 0x40) = *(uint *)(unaff_ESI + 0x40) | 1;
  }
  return;
}

