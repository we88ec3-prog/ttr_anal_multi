
void FUN_00432ac0(wint_t *param_1)

{
  wint_t *pwVar1;
  wint_t _WCh;
  uint uVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 *unaff_ESI;
  wint_t *pwVar5;
  uint in_stack_00000018;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  puStack_c = &LAB_00917ba1;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  unaff_ESI[5] = 0xf;
  unaff_ESI[4] = 0;
  *(undefined1 *)unaff_ESI = 0;
  pwVar5 = param_1;
  if (in_stack_00000018 < 8) {
    pwVar5 = (wint_t *)&param_1;
  }
  _WCh = *pwVar5;
  while (_WCh != 0) {
    local_14 = _wctob(_WCh);
    local_14 = local_14 & 0xff;
    puVar4 = unaff_ESI;
    if (0xf < (uint)unaff_ESI[5]) {
      puVar4 = (undefined4 *)*unaff_ESI;
    }
    puVar3 = (undefined1 *)(unaff_ESI[4] + (int)puVar4);
    puVar4 = unaff_ESI;
    if (0xf < (uint)unaff_ESI[5]) {
      puVar4 = (undefined4 *)*unaff_ESI;
    }
    if (puVar3 != (undefined1 *)0x0) {
      puVar3 = puVar3 + -(int)puVar4;
    }
    FUN_004329c0(puVar3,1,local_14);
    pwVar1 = pwVar5 + 1;
    pwVar5 = pwVar5 + 1;
    _WCh = *pwVar1;
  }
  if (7 < in_stack_00000018) {
    FUN_0089120c(param_1,uVar2);
  }
  ExceptionList = local_10;
  return;
}

