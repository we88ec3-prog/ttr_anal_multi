
char * FUN_0071be00(char *param_1,char *param_2)

{
  uint uVar1;
  int iVar2;
  char *_Src;
  undefined4 *in_ECX;
  uint _Size;
  undefined **local_10 [3];
  
  _Src = param_1;
  uVar1 = in_ECX[1];
  _Size = (int)param_2 + 3U & 0xfffffffc;
  if (param_1 != (char *)0x0) {
    in_ECX[1] = uVar1 - _Size;
  }
  param_1._3_1_ = uVar1 == _Size;
  param_2 = (char *)FUN_0071bdb0();
  if (param_2 != (char *)0x0) {
    if (((param_2 != _Src) && (_Src != (char *)0x0)) &&
       (FID_conflict__memcpy(param_2,_Src,_Size), param_1._3_1_ != '\0')) {
      iVar2 = **(int **)*in_ECX;
      if (iVar2 != 0) {
        (*(code *)PTR_FUN_00d63d4c)(*(int **)*in_ECX);
        *(int *)*in_ECX = iVar2;
      }
    }
    return param_2;
  }
  param_1 = "bad allocation";
  std::exception::exception((exception *)local_10,&param_1,1);
  local_10[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_10,&DAT_00c857a8);
}

