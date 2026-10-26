
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_004f6b80(void)

{
  void *pvVar1;
  size_t sVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int unaff_ESI;
  undefined4 local_2010 [1024];
  uint local_1010;
  undefined4 local_100c [1024];
  uint local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(int *)(unaff_ESI + 0x110) != *(int *)(unaff_ESI + 0x114)) {
    local_100c[0]._0_2_ = 0x13;
    uVar6 = 2;
    uVar4 = *(int *)(unaff_ESI + 0x114) - *(int *)(unaff_ESI + 0x110) >> 2;
    uVar5 = 0;
    local_c = 2;
    if (uVar4 != 0) {
      do {
        if (0x13 < uVar5) break;
        if (uVar6 + 4 < 0x1001) {
          *(undefined4 *)((int)local_100c + uVar6) =
               *(undefined4 *)(*(int *)(unaff_ESI + 0x110) + uVar5 * 4);
          uVar6 = local_c + 4;
          local_c = uVar6;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar4);
    }
    pvVar3 = *(void **)(unaff_ESI + 0x110);
    pvVar1 = (void *)((int)pvVar3 + uVar5 * 4);
    if (pvVar3 != pvVar1) {
      sVar2 = (*(int *)(unaff_ESI + 0x114) - (int)pvVar1 >> 2) * 4;
      FID_conflict__memcpy(pvVar3,pvVar1,sVar2);
      *(void **)(unaff_ESI + 0x114) = (void *)(sVar2 + (int)pvVar3);
      uVar6 = local_c;
    }
    if (2 < uVar6) {
      (**(code **)(*DAT_00fba854 + 0x10))(2,local_100c,uVar6);
    }
  }
  if (*(int *)(unaff_ESI + 0x130) != *(int *)(unaff_ESI + 0x134)) {
    local_2010[0]._0_2_ = 0xbc6;
    uVar6 = 2;
    uVar5 = *(int *)(unaff_ESI + 0x134) - *(int *)(unaff_ESI + 0x130) >> 2;
    uVar4 = 0;
    local_1010 = 2;
    if (uVar5 != 0) {
      do {
        if (0x13 < uVar4) break;
        if (uVar6 + 4 < 0x1001) {
          *(undefined4 *)((int)local_2010 + uVar6) =
               *(undefined4 *)(*(int *)(unaff_ESI + 0x130) + uVar4 * 4);
          uVar6 = local_1010 + 4;
          local_1010 = uVar6;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar5);
    }
    pvVar3 = *(void **)(unaff_ESI + 0x130);
    pvVar1 = (void *)((int)pvVar3 + uVar4 * 4);
    if (pvVar3 != pvVar1) {
      sVar2 = (*(int *)(unaff_ESI + 0x134) - (int)pvVar1 >> 2) * 4;
      FID_conflict__memcpy(pvVar3,pvVar1,sVar2);
      *(void **)(unaff_ESI + 0x134) = (void *)(sVar2 + (int)pvVar3);
      uVar6 = local_1010;
    }
    if (2 < uVar6) {
      (**(code **)(*DAT_00fba854 + 0x10))(2,local_2010,uVar6);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

