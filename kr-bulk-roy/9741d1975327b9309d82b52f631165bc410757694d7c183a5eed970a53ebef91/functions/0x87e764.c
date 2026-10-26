
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    private: static void __cdecl std::locale::_Locimp::_Locimp_Addfac(class std::locale::_Locimp
   *,class std::locale::facet *,unsigned int)
   
   Library: Visual Studio 2010 Release */

void __cdecl std::locale::_Locimp::_Locimp_Addfac(_Locimp *param_1,facet *param_2,uint param_3)

{
  _Locimp *p_Var1;
  uint uVar2;
  void *pvVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined **local_20 [3];
  _Lockit local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x87e770;
  _Lockit::_Lockit(local_14,0);
  uVar2 = param_3;
  p_Var1 = param_1;
  local_8 = 0;
  if (*(uint *)(param_1 + 0xc) <= param_3) {
    uVar5 = param_3 + 1;
    if (uVar5 < 0x28) {
      uVar5 = 0x28;
    }
    pvVar3 = __realloc_crt(*(void **)(param_1 + 8),uVar5 << 2);
    if (pvVar3 == (void *)0x0) {
      if ((_DAT_00f8c96c & 1) == 0) {
        _DAT_00f8c96c = _DAT_00f8c96c | 1;
        param_1 = (_Locimp *)s_bad_allocation_00c411b0;
        exception::exception((exception *)&DAT_00f8c960,(char **)&param_1,1);
        _DAT_00f8c960 = bad_alloc::vftable;
        _atexit((_func_4879 *)&LAB_00bd11a4);
      }
      exception::exception((exception *)local_20,(exception *)&DAT_00f8c960);
      local_20[0] = bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_20,&DAT_00c857a8);
    }
    *(void **)(p_Var1 + 8) = pvVar3;
    while (*(uint *)(p_Var1 + 0xc) < uVar5) {
      *(undefined4 *)(*(int *)(p_Var1 + 8) + *(int *)(p_Var1 + 0xc) * 4) = 0;
      *(int *)(p_Var1 + 0xc) = *(int *)(p_Var1 + 0xc) + 1;
    }
  }
  FUN_00431db0();
  if (*(int *)(*(int *)(p_Var1 + 8) + uVar2 * 4) != 0) {
    puVar4 = (undefined4 *)FUN_00432770();
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)(1);
    }
  }
  local_8 = 0xffffffff;
  *(facet **)(*(int *)(p_Var1 + 8) + uVar2 * 4) = param_2;
  FUN_0087dd6f();
  return;
}

