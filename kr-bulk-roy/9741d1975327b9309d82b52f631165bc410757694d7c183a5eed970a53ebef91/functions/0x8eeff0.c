
void FUN_008eeff0(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  bool bVar4;
  uint in_EAX;
  uint uVar5;
  int iVar6;
  uint in_ECX;
  int iVar7;
  int iVar8;
  int *unaff_ESI;
  int iVar9;
  int local_18;
  int local_c;
  
  if (((param_1 <= param_2) && (in_EAX < (uint)unaff_ESI[3])) && (in_ECX < (uint)unaff_ESI[3])) {
    iVar1 = *(int *)(unaff_ESI[2] + in_EAX * 8);
    local_c = *(int *)(unaff_ESI[2] + in_ECX * 8);
    uVar5 = in_EAX;
    iVar9 = iVar1;
    if (local_c < iVar1) {
      uVar5 = in_ECX;
      in_ECX = in_EAX;
      iVar9 = local_c;
      local_c = iVar1;
    }
    iVar1 = *(int *)(*unaff_ESI + uVar5 * 8);
    iVar2 = *(int *)(*unaff_ESI + in_ECX * 8);
    iVar7 = *(int *)(unaff_ESI[1] + in_ECX * 8) - iVar2;
    iVar8 = *(int *)(unaff_ESI[1] + uVar5 * 8) - iVar1;
    if (iVar9 == local_c) {
      do {
        iVar9 = *(int *)(*unaff_ESI + param_1 * 8);
        iVar2 = iVar7;
        if (iVar9 <= iVar1) {
          iVar2 = iVar8;
        }
        *(int *)(unaff_ESI[1] + param_1 * 8) = iVar9 + iVar2;
        param_1 = param_1 + 1;
      } while (param_1 <= param_2);
      return;
    }
    local_18 = 0;
    bVar4 = false;
    do {
      iVar6 = *(int *)(*unaff_ESI + param_1 * 8);
      if (iVar1 < iVar6) {
        if (iVar6 < iVar2) {
          if (!bVar4) {
            bVar4 = true;
            local_18 = FUN_008b7f40(((iVar7 - iVar8) - iVar1) + iVar2,local_c - iVar9);
          }
          lVar3 = (longlong)(*(int *)(unaff_ESI[2] + param_1 * 8) - iVar9) * (longlong)local_18;
          lVar3 = lVar3 + (ulonglong)((int)(lVar3 >> 0x3f) + 0x8000);
          iVar6 = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000 + iVar8 + iVar1;
        }
        else {
          iVar6 = iVar6 + iVar7;
        }
      }
      else {
        iVar6 = iVar6 + iVar8;
      }
      *(int *)(unaff_ESI[1] + param_1 * 8) = iVar6;
      param_1 = param_1 + 1;
    } while (param_1 <= param_2);
  }
  return;
}

