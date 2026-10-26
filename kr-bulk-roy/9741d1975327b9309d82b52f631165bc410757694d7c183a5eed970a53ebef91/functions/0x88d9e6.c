
/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    protected: void __thiscall std::_Mpunct<char>::_Init(class std::_Locinfo const &,bool)
   
   Library: Visual Studio 2010 Release */

void __thiscall std::_Mpunct<char>::_Init(_Mpunct<char> *this,_Locinfo *param_1,bool param_2)

{
  _Collvec *p_Var1;
  char cVar2;
  lconv *plVar3;
  undefined4 uVar4;
  char *pcVar5;
  _Collvec _Var7;
  int iVar6;
  
  _Var7 = __Getcoll();
  p_Var1 = (_Collvec *)(this + 0x2c);
  *p_Var1 = _Var7;
  plVar3 = _localeconv();
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  uVar4 = FUN_00430270(plVar3->mon_grouping,0,p_Var1);
  *(undefined4 *)(this + 8) = uVar4;
  if (this[0x28] == (_Mpunct<char>)0x0) {
    pcVar5 = plVar3->currency_symbol;
  }
  else {
    pcVar5 = plVar3->int_curr_symbol;
  }
  uVar4 = FUN_00430270(pcVar5,0,p_Var1);
  *(undefined4 *)(this + 0x10) = uVar4;
  pcVar5 = "";
  if ((byte)plVar3->p_sign_posn < 5) {
    pcVar5 = plVar3->positive_sign;
  }
  uVar4 = FUN_00430270(pcVar5,0,p_Var1);
  *(undefined4 *)(this + 0x14) = uVar4;
  pcVar5 = "-";
  if ((byte)plVar3->n_sign_posn < 5) {
    pcVar5 = plVar3->negative_sign;
  }
  uVar4 = FUN_00430270(pcVar5,0,p_Var1);
  *(undefined4 *)(this + 0x18) = uVar4;
  this[0xc] = *(_Mpunct<char> *)plVar3->mon_decimal_point;
  this[0xd] = *(_Mpunct<char> *)plVar3->mon_thousands_sep;
  if (this[0x28] == (_Mpunct<char>)0x0) {
    cVar2 = plVar3->frac_digits;
  }
  else {
    cVar2 = plVar3->int_frac_digits;
  }
  iVar6 = (int)cVar2;
  *(int *)(this + 0x1c) = iVar6;
  if ((iVar6 < 0) || (0x7e < iVar6)) {
    *(undefined4 *)(this + 0x1c) = 0;
  }
  Makpat(this + 0x20,(int)plVar3->p_sep_by_space,(int)plVar3->p_cs_precedes,(int)plVar3->p_sign_posn
        );
  Makpat(this + 0x24,(int)plVar3->n_sep_by_space,(int)plVar3->n_cs_precedes,(int)plVar3->n_sign_posn
        );
  if (param_2) {
    FID_conflict__memcpy(this + 0x20,&DAT_00bd2ed8,4);
    FID_conflict__memcpy(this + 0x24,&DAT_00bd2ed8,4);
  }
  return;
}

