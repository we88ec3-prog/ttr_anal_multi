
/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_008827c2(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  
  uVar3 = param_1 | 7;
  if (uVar3 < 0x7fffffff) {
    uVar1 = *(uint *)(in_ECX + 0x14);
    uVar2 = uVar1 >> 1;
    param_1 = uVar3;
    if ((uVar3 / 3 < uVar2) && (param_1 = 0x7ffffffe, uVar1 <= 0x7ffffffe - uVar2)) {
      param_1 = uVar2 + uVar1;
    }
  }
  FUN_0044bb70(param_1 + 1,0);
  FUN_0088284c();
  return;
}

