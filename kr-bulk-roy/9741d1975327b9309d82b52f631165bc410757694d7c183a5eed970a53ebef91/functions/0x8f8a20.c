
void FUN_008f8a20(void)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int *unaff_EDI;
  int local_910;
  int *local_90c;
  uint local_908;
  undefined1 local_904 [8];
  undefined4 local_8fc;
  undefined4 local_8f8;
  undefined4 local_8f4;
  undefined4 local_8f0;
  undefined4 local_8ec;
  undefined4 local_8e8;
  uint local_8dc;
  undefined1 local_80 [44];
  int local_54 [19];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  FUN_008f42a0(*(undefined4 *)(in_ECX + 100));
  unaff_EDI[0xd] = 0;
  unaff_EDI[0x118] = 0;
  puVar1 = (&PTR_DAT_00bebb88)[*(int *)(*unaff_EDI + 8)];
  FUN_008f7580();
  if ((((local_908 != 0) ||
       ((*(int *)(puVar1 + 0xc) != 0 &&
        ((FUN_008f7580(), local_908 != 0 ||
         ((*(int *)(puVar1 + 0x10) != 0 && (FUN_008f7580(), local_908 != 0)))))))) &&
      (iVar3 = FUN_008bb2e0(), iVar3 == 0)) &&
     (iVar3 = *(int *)(in_ECX + 0x54), 0 < *(short *)(iVar3 + 0x6e))) {
    _memset(local_904,0,0x884);
    local_8dc = unaff_EDI[10];
    local_8fc = 0x10000;
    local_8f8 = 0x10000;
    local_8f4 = 0;
    local_8f0 = 0;
    local_8ec = 0;
    local_8e8 = 0;
    FUN_008f4350();
    iVar3 = FUN_008f4360(iVar3 + 0x6c);
    if (iVar3 == 0) {
      piVar6 = local_54;
      local_90c = unaff_EDI + 0xe;
      local_910 = 0;
      do {
        local_908 = 0;
        iVar3 = FUN_008f5160();
        if (iVar3 != 0) break;
        FUN_008f5430();
        uVar4 = piVar6[2];
        uVar5 = *piVar6 * 0x30 + uVar4;
        piVar7 = local_90c;
        for (; uVar4 < uVar5; uVar4 = uVar4 + 0x30) {
          uVar2 = *(uint *)(uVar4 + 0x14);
          if (((uVar2 != 0) && (*(uint *)(uVar2 + 0x14) == uVar4)) && (uVar4 < uVar2)) {
            iVar3 = (int)*(short *)(uVar4 + 2) - (int)*(short *)(uVar2 + 2);
            if (iVar3 < 0) {
              iVar3 = -iVar3;
            }
            if (local_908 < 0x10) {
              local_908 = local_908 + 1;
              *piVar7 = iVar3;
              piVar7 = piVar7 + 3;
            }
          }
        }
        FUN_008f3d70(&local_908,local_90c,local_8dc / 100);
        local_910 = local_910 + 1;
        local_90c[-1] = local_908;
        local_90c = local_90c + 0x10b;
        piVar6 = piVar6 + 7;
      } while (local_910 < 2);
    }
  }
  if (unaff_EDI[0xd] == 0) {
    iVar3 = (int)((unaff_EDI[10] * 0x32 >> 0x1f & 0x7ffU) + unaff_EDI[10] * 0x32) >> 0xb;
  }
  else {
    iVar3 = unaff_EDI[0xe];
  }
  unaff_EDI[0x3e] = iVar3 / 5;
  unaff_EDI[0x3f] = iVar3;
  *(undefined1 *)(unaff_EDI + 0x40) = 0;
  if (unaff_EDI[0x118] == 0) {
    iVar3 = (int)((unaff_EDI[10] * 0x32 >> 0x1f & 0x7ffU) + unaff_EDI[10] * 0x32) >> 0xb;
  }
  else {
    iVar3 = unaff_EDI[0x119];
  }
  unaff_EDI[0x149] = iVar3 / 5;
  unaff_EDI[0x14a] = iVar3;
  *(undefined1 *)(unaff_EDI + 0x14b) = 0;
  FUN_008f42c0(local_80);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

