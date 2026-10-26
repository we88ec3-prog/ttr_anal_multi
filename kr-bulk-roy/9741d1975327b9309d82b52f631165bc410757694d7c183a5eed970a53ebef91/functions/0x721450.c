
void FUN_00721450(char *param_1,char *param_2)

{
  undefined4 *puVar1;
  size_t _Size;
  void *_Dst;
  uint uVar2;
  int unaff_EDI;
  undefined **local_10 [3];
  
  uVar2 = (int)param_2 - (int)param_1 >> 3;
  if (uVar2 < 2) {
    puVar1 = (undefined4 *)(unaff_EDI + 4);
    if (*(undefined4 **)(unaff_EDI + 0xc) != puVar1) {
      (*(code *)PTR_FUN_00d63d4c)(*(undefined4 **)(unaff_EDI + 0xc));
    }
    if (param_1 != param_2) {
      *puVar1 = *(undefined4 *)param_1;
      *(undefined4 *)(unaff_EDI + 8) = *(undefined4 *)(param_1 + 4);
    }
    *(undefined4 **)(unaff_EDI + 0xc) = puVar1;
    *(uint *)(unaff_EDI + 0x10) = unaff_EDI + 4 + uVar2 * 8;
    return;
  }
  _Size = uVar2 * 8;
  _Dst = (void *)(*(code *)PTR_FUN_00d63d48)(_Size);
  if (_Dst == (void *)0x0) {
    param_1 = "bad allocation";
    std::exception::exception((exception *)local_10,&param_1,1);
    local_10[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_10,&DAT_00c857a8);
  }
  FID_conflict__memcpy(_Dst,param_1,_Size);
  if (*(int *)(unaff_EDI + 0xc) != unaff_EDI + 4) {
    (*(code *)PTR_FUN_00d63d4c)(*(int *)(unaff_EDI + 0xc));
  }
  *(void **)(unaff_EDI + 0xc) = _Dst;
  *(void **)(unaff_EDI + 0x10) = (void *)(_Size + (int)_Dst);
  return;
}

