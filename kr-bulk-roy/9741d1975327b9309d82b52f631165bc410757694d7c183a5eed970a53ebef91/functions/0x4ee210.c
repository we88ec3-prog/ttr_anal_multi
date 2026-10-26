
void FUN_004ee210(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  int in_ECX;
  code *in_EDX;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar4 = (param_1 - in_ECX) / 0xc;
  iVar7 = iVar4 / 2;
  if (0 < iVar7) {
    iVar9 = iVar7 * 2 + 2;
    iVar8 = in_ECX + iVar7 * 0xc;
    do {
      local_14 = *(undefined4 *)(iVar8 + -0xc);
      local_10 = *(undefined4 *)(iVar8 + -8);
      iVar7 = iVar7 + -1;
      iVar9 = iVar9 + -2;
      local_c = *(undefined4 *)(iVar8 + -4);
      iVar5 = iVar7;
      for (iVar10 = iVar9; iVar10 < iVar4; iVar10 = iVar10 * 2 + 2) {
        iVar1 = in_ECX + iVar10 * 0xc;
        cVar6 = (*in_EDX)(iVar1,iVar1 + -0xc);
        if (cVar6 != '\0') {
          iVar10 = iVar10 + -1;
        }
        puVar2 = (undefined4 *)(in_ECX + iVar10 * 0xc);
        puVar3 = (undefined4 *)(in_ECX + iVar5 * 0xc);
        *puVar3 = *puVar2;
        puVar3[1] = puVar2[1];
        puVar3[2] = puVar2[2];
        iVar5 = iVar10;
      }
      if (iVar10 == iVar4) {
        iVar10 = in_ECX + -0xc + iVar4 * 0xc;
        puVar2 = (undefined4 *)(in_ECX + iVar5 * 0xc);
        *puVar2 = *(undefined4 *)(in_ECX + -0xc + iVar4 * 0xc);
        puVar2[1] = *(undefined4 *)(iVar10 + 4);
        puVar2[2] = *(undefined4 *)(iVar10 + 8);
      }
      FUN_004ee690(in_ECX,iVar7,&local_14,in_EDX);
      iVar8 = iVar8 + -0xc;
    } while (0 < iVar7);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

