
/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Same Base Name
    protected: void __thiscall std::_Mpunct<unsigned short>::_Init(class std::_Locinfo const &,bool)
    protected: void __thiscall std::_Mpunct<wchar_t>::_Init(class std::_Locinfo const &,bool)
   
   Library: Visual Studio 2010 Release */

void Init(undefined4 param_1,char param_2)

{
  _Collvec *p_Var1;
  char cVar2;
  undefined2 uVar3;
  lconv *plVar4;
  undefined4 uVar5;
  char *pcVar6;
  int in_ECX;
  _Collvec _Var8;
  int iVar7;
  
  _Var8 = __Getcoll();
  p_Var1 = (_Collvec *)(in_ECX + 0x2c);
  *p_Var1 = _Var8;
  plVar4 = _localeconv();
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  uVar5 = FUN_00430270(plVar4->mon_grouping,0,p_Var1);
  *(undefined4 *)(in_ECX + 8) = uVar5;
  if (*(char *)(in_ECX + 0x28) == '\0') {
    pcVar6 = plVar4->currency_symbol;
  }
  else {
    pcVar6 = plVar4->int_curr_symbol;
  }
  uVar5 = FUN_004302b0(pcVar6,0,p_Var1);
  *(undefined4 *)(in_ECX + 0x10) = uVar5;
  pcVar6 = "";
  if ((byte)plVar4->p_sign_posn < 5) {
    pcVar6 = plVar4->positive_sign;
  }
  uVar5 = FUN_004302b0(pcVar6,0,p_Var1);
  *(undefined4 *)(in_ECX + 0x14) = uVar5;
  pcVar6 = "-";
  if ((byte)plVar4->n_sign_posn < 5) {
    pcVar6 = plVar4->negative_sign;
  }
  uVar5 = FUN_004302b0(pcVar6,0,p_Var1);
  *(undefined4 *)(in_ECX + 0x18) = uVar5;
  uVar3 = FUN_004303a0(*plVar4->mon_decimal_point,0,p_Var1);
  *(undefined2 *)(in_ECX + 0xc) = uVar3;
  uVar3 = FUN_004303a0(*plVar4->mon_thousands_sep,0,p_Var1);
  *(undefined2 *)(in_ECX + 0xe) = uVar3;
  if (*(char *)(in_ECX + 0x28) == '\0') {
    cVar2 = plVar4->frac_digits;
  }
  else {
    cVar2 = plVar4->int_frac_digits;
  }
  iVar7 = (int)cVar2;
  *(int *)(in_ECX + 0x1c) = iVar7;
  if ((iVar7 < 0) || (0x7e < iVar7)) {
    *(undefined4 *)(in_ECX + 0x1c) = 0;
  }
  Makpat((void *)(in_ECX + 0x20),(int)plVar4->p_sep_by_space,(int)plVar4->p_cs_precedes,
         (int)plVar4->p_sign_posn);
  Makpat((void *)(in_ECX + 0x24),(int)plVar4->n_sep_by_space,(int)plVar4->n_cs_precedes,
         (int)plVar4->n_sign_posn);
  if (param_2 != '\0') {
    FID_conflict__memcpy((void *)(in_ECX + 0x20),&DAT_00bd2ed8,4);
    FID_conflict__memcpy((void *)(in_ECX + 0x24),&DAT_00bd2ed8,4);
  }
  return;
}

