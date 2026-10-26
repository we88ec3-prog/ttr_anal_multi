
void FUN_00734ce0(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *in_ECX;
  int iVar6;
  int iVar7;
  char cVar8;
  uint *puVar9;
  int local_14;
  uint *local_10;
  uint local_8;
  
  uVar1 = *in_ECX;
  uVar2 = *param_1;
  uVar4 = param_1[1];
  uVar3 = in_ECX[1] / uVar4;
  local_8 = ((in_ECX[2] - *in_ECX) + -1 + uVar2) / uVar2;
  uVar4 = ((in_ECX[3] - in_ECX[1]) + -1 + uVar4) / uVar4;
  if (local_8 == 0) {
    local_8 = 1;
  }
  if (uVar4 == 0) {
    uVar4 = 1;
  }
  if ((int)uVar3 < (int)(uVar4 + uVar3)) {
    puVar9 = param_1 + uVar3 * 8 + 0x46;
    local_10 = param_1 + uVar3 + 6;
    iVar6 = -0x118 - (int)param_1;
    local_14 = (uVar4 + uVar3) - uVar3;
    do {
      cVar8 = *(char *)((int)puVar9 + uVar1 / uVar2);
      if (cVar8 < '\0') {
        uVar4 = uVar1 / uVar2 - (int)cVar8;
        if ((int)uVar4 < (int)param_1[2]) {
          cVar8 = *(char *)((int)puVar9 + uVar4 + iVar6 + 0x118 + (int)param_1);
          if (cVar8 < '\x01') {
            cVar8 = '\x01';
          }
          else {
            cVar8 = cVar8 + '\x01';
          }
        }
        else {
          cVar8 = '\x01';
          uVar4 = param_1[2];
        }
        iVar5 = uVar4 - 1;
        if (*(char *)((int)puVar9 + iVar5 + iVar6 + 0x118 + (int)param_1) < '\0') {
          iVar7 = iVar5 - local_8;
          for (; (int)(((int)(iVar7 + 1U) < 0) - 1 & iVar7 + 1U) <= iVar5; iVar5 = iVar5 + -1) {
            *(char *)((int)puVar9 + iVar5) = cVar8;
            cVar8 = cVar8 + '\x01';
          }
          *local_10 = *local_10 + local_8;
          if ((int)param_1[2] < (int)*local_10) {
            FID_conflict__wprintf("Err#6\n");
            *local_10 = param_1[2];
          }
          if (-1 < iVar7) {
            if (*(char *)((int)puVar9 + iVar7 + iVar6 + 0x118 + (int)param_1) == '\0') {
              FID_conflict__wprintf("Err#5\n");
            }
            else {
              do {
                if (*(char *)((int)puVar9 + iVar7) < '\x01') break;
                *(char *)((int)puVar9 + iVar7) = cVar8;
                cVar8 = cVar8 + '\x01';
                iVar7 = iVar7 + -1;
              } while (-1 < iVar7);
            }
          }
        }
        else {
          FID_conflict__wprintf("Err#4\n");
        }
      }
      else {
        FID_conflict__wprintf("Err#2\n");
      }
      local_10 = local_10 + 1;
      puVar9 = puVar9 + 8;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
  }
  return;
}

