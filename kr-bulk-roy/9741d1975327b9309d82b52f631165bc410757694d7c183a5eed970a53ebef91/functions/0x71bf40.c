
void * FUN_0071bf40(void *param_1,char *param_2)

{
  char *_Size;
  void *_Dst;
  undefined **local_10 [3];
  
  _Size = param_2;
  _Dst = (void *)FUN_0071bdb0();
  if (_Dst == (void *)0x0) {
    param_2 = "bad allocation";
    std::exception::exception((exception *)local_10,&param_2,1);
    local_10[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_10,&DAT_00c857a8);
  }
  FID_conflict__memcpy(_Dst,param_1,(size_t)_Size);
  *(char *)((int)_Dst + (int)_Size) = '\0';
  return _Dst;
}

