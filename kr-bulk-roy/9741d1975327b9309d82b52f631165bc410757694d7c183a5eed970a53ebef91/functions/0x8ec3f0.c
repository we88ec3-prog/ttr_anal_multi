
uint FUN_008ec3f0(int param_1)

{
  uint uVar1;
  int in_EAX;
  uint uVar2;
  uint uVar3;
  uint in_ECX;
  uint uVar4;
  uint in_EDX;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  uVar2 = (in_ECX & 0xffff) * param_1;
  param_1 = ((int)in_ECX >> 0x10) * param_1;
  uVar4 = param_1 * 0x10000 + uVar2;
  uVar3 = (in_EDX & 0xffff) * in_EAX;
  iVar5 = ((int)in_EDX >> 0x10) * in_EAX;
  uVar7 = iVar5 * 0x10000 + uVar3;
  uVar1 = uVar7 + uVar4;
  iVar6 = (iVar5 >> 0x10) + (uint)(uVar4 < uVar2) + (param_1 >> 0x10) + ((int)uVar2 >> 0x1f) +
          (uint)(uVar1 < uVar4) + (uint)(uVar7 < uVar3) + ((int)uVar3 >> 0x1f);
  iVar5 = iVar6 >> 0x1f;
  uVar2 = iVar5 + uVar1;
  return ((uint)(uVar2 + 0x2000 < uVar2) + iVar6 + (uint)(uVar2 < uVar1) + iVar5) * 0x40000 |
         uVar2 + 0x2000 >> 0xe;
}

