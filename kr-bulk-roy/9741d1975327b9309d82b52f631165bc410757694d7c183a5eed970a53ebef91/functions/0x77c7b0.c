
void FUN_0077c7b0(wchar_t *param_1)

{
  short *psVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  wchar_t local_408 [256];
  wchar_t local_208 [256];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  __wsplitpath(param_1,(wchar_t *)0x0,(wchar_t *)0x0,local_208,local_408);
  pwVar3 = local_208;
  iVar6 = in_ECX - (int)pwVar3;
  do {
    wVar2 = *pwVar3;
    *(wchar_t *)(iVar6 + (int)pwVar3) = wVar2;
    pwVar3 = pwVar3 + 1;
  } while (wVar2 != L'\0');
  pwVar3 = local_408;
  do {
    wVar2 = *pwVar3;
    pwVar3 = pwVar3 + 1;
  } while (wVar2 != L'\0');
  uVar4 = (int)pwVar3 - (int)local_408;
  puVar7 = (undefined4 *)(in_ECX + -2);
  do {
    psVar1 = (short *)((int)puVar7 + 2);
    puVar7 = (undefined4 *)((int)puVar7 + 2);
  } while (*psVar1 != 0);
  pwVar3 = local_408;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar7 = *(undefined4 *)pwVar3;
    pwVar3 = pwVar3 + 2;
    puVar7 = puVar7 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(char *)puVar7 = (char)*pwVar3;
    pwVar3 = (wchar_t *)((int)pwVar3 + 1);
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

