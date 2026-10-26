
/* Library Function - Single Match
    _vscan_fn
   
   Library: Visual Studio 2010 Release */

undefined4 __cdecl vscan_fn(code *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  size_t sVar2;
  undefined4 uVar3;
  int iVar4;
  wchar_t *unaff_ESI;
  int local_20;
  undefined4 local_18;
  
  piVar1 = &local_20;
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar1 = 0;
    piVar1 = piVar1 + 1;
  }
  if ((unaff_ESI != (wchar_t *)0x0) && (param_2 != 0)) {
    sVar2 = _wcslen(unaff_ESI);
    local_18 = 0x49;
    if (sVar2 < 0x40000000) {
      local_20 = sVar2 * 2;
    }
    else {
      local_20 = 0x7fffffff;
    }
    uVar3 = (*param_1)(&stack0xffffffdc,param_2,param_3,param_4);
    return uVar3;
  }
  piVar1 = __errno();
  *piVar1 = 0x16;
  FUN_00893343();
  return 0xffffffff;
}

