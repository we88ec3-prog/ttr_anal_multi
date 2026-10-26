
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _raise
   
   Library: Visual Studio 2010 Release */

int __cdecl _raise(int _SigNum)

{
  int iVar1;
  int *piVar2;
  PVOID Ptr;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  _ptiddata p_Var6;
  int local_34;
  void *local_30;
  int local_28;
  int local_20;
  
  p_Var6 = (_ptiddata)0x0;
  local_20 = 0;
  if (_SigNum < 0xc) {
    if (_SigNum != 0xb) {
      if (_SigNum == 2) {
        puVar5 = &DAT_00f8d670;
        Ptr = DAT_00f8d670;
        goto LAB_008a7613;
      }
      if (_SigNum != 4) {
        if (_SigNum == 6) goto LAB_008a75f1;
        if (_SigNum != 8) goto LAB_008a75df;
      }
    }
    p_Var6 = __getptd_noexit();
    if (p_Var6 == (_ptiddata)0x0) {
      return -1;
    }
    iVar1 = siglookup(p_Var6->_pxcptacttab);
    puVar5 = (undefined4 *)(iVar1 + 8);
    pcVar3 = (code *)*puVar5;
  }
  else {
    if (_SigNum == 0xf) {
      puVar5 = &DAT_00f8d67c;
      Ptr = DAT_00f8d67c;
    }
    else if (_SigNum == 0x15) {
      puVar5 = &DAT_00f8d674;
      Ptr = DAT_00f8d674;
    }
    else {
      if (_SigNum != 0x16) {
LAB_008a75df:
        piVar2 = __errno();
        *piVar2 = 0x16;
        FUN_00893343();
        return -1;
      }
LAB_008a75f1:
      puVar5 = &DAT_00f8d678;
      Ptr = DAT_00f8d678;
    }
LAB_008a7613:
    local_20 = 1;
    pcVar3 = DecodePointer(Ptr);
  }
  iVar1 = 0;
  if (pcVar3 == (code *)0x1) {
    return 0;
  }
  if (pcVar3 == (code *)0x0) {
    iVar1 = __exit(3);
  }
  if (local_20 != iVar1) {
    __lock(iVar1);
  }
  if (((_SigNum == 8) || (_SigNum == 0xb)) || (_SigNum == 4)) {
    local_30 = p_Var6->_tpxcptinfoptrs;
    p_Var6->_tpxcptinfoptrs = (void *)0x0;
    if (_SigNum == 8) {
      local_34 = p_Var6->_tfpecode;
      p_Var6->_tfpecode = 0x8c;
      goto LAB_008a7677;
    }
  }
  else {
LAB_008a7677:
    if (_SigNum == 8) {
      for (local_28 = 3; local_28 < 0xc; local_28 = local_28 + 1) {
        *(undefined4 *)(local_28 * 0xc + 8 + (int)p_Var6->_pxcptacttab) = 0;
      }
      goto LAB_008a76af;
    }
  }
  uVar4 = FUN_008a5543();
  *puVar5 = uVar4;
LAB_008a76af:
  FUN_008a76d0();
  if (_SigNum == 8) {
    (*pcVar3)(8,p_Var6->_tfpecode);
  }
  else {
    (*pcVar3)(_SigNum);
    if ((_SigNum != 0xb) && (_SigNum != 4)) {
      return 0;
    }
  }
  p_Var6->_tpxcptinfoptrs = local_30;
  if (_SigNum == 8) {
    p_Var6->_tfpecode = local_34;
  }
  return 0;
}

