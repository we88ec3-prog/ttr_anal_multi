
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _vfscanf
   
   Library: Visual Studio 2010 Release */

int __cdecl vfscanf(code *param_1,FILE *param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  uint uVar2;
  undefined *puVar3;
  int local_20;
  
  local_20 = 0;
  if ((param_2 == (FILE *)0x0) || (param_3 == 0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    return -1;
  }
  __lock_file(param_2);
  if ((param_2->_flag & 0x40) == 0) {
    uVar2 = __fileno(param_2);
    if ((uVar2 == 0xffffffff) || (uVar2 == 0xfffffffe)) {
      puVar3 = &DAT_00d61f50;
    }
    else {
      puVar3 = (undefined *)((uVar2 & 0x1f) * 0x40 + (&DAT_00fe72a0)[(int)uVar2 >> 5]);
    }
    if ((puVar3[0x24] & 0x7f) == 0) {
      if ((uVar2 == 0xffffffff) || (uVar2 == 0xfffffffe)) {
        puVar3 = &DAT_00d61f50;
      }
      else {
        puVar3 = (undefined *)((uVar2 & 0x1f) * 0x40 + (&DAT_00fe72a0)[(int)uVar2 >> 5]);
      }
      if ((puVar3[0x24] & 0x80) == 0) goto LAB_00899592;
    }
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    local_20 = -1;
  }
LAB_00899592:
  if (local_20 == 0) {
    local_20 = (*param_1)(param_2,param_3,param_4,param_5);
  }
  FUN_008995c2();
  return local_20;
}

