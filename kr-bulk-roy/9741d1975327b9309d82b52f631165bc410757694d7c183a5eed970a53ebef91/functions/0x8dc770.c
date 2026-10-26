
void FUN_008dc770(int param_1,int param_2,uint param_3,uint param_4)

{
  undefined2 *puVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int local_614;
  int local_610;
  int local_60c;
  uint local_608;
  undefined1 local_604 [16];
  int local_5f4;
  undefined4 local_5e4;
  undefined4 local_5dc;
  byte local_5bf;
  int local_5bc;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  int local_94;
  int local_90;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar5 = *(int *)(param_1 + 4);
  local_60c = *(int *)(iVar5 + 0x88);
  if (*(uint *)(iVar5 + 0x10) <= param_3) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if ((param_4 & 0x400) != 0) {
    param_4 = param_4 | 3;
  }
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_2 + 0x14);
  *(undefined2 *)(param_1 + 0x6e) = 0;
  puVar1 = (undefined2 *)(param_1 + 0x6c);
  *puVar1 = 0;
  local_608 = param_4 & 1;
  if ((local_608 != 0) || (cVar3 = '\x01', (param_4 & 2) != 0)) {
    cVar3 = '\0';
  }
  *(undefined4 *)(param_1 + 0x48) = 0x6f75746c;
  iVar4 = (*(code *)**(undefined4 **)(local_60c + 0xc))
                    (local_604,iVar5,param_2,param_1,0,0,cVar3,(int)param_4 >> 0x10 & 0xf,
                     FUN_008dc400);
  if (iVar4 == 0) {
    local_5bf = (byte)(param_4 >> 10) & 1;
    iVar4 = FUN_008dc400(local_604,param_3);
    if (iVar4 == 0) {
      local_18 = local_a4;
      local_10 = local_9c;
      local_14 = local_a0;
      local_c = local_98;
      (**(code **)(*(int *)(local_60c + 0xc) + 4))(local_604);
      *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) & 1 | 4;
      if ((param_4 & 0x400) != 0) {
        iVar5 = *(int *)(param_1 + 0x9c);
        iVar4 = FUN_008b7c80(local_5e4);
        *(int *)(param_1 + 0x20) = iVar4 >> 0x10;
        iVar4 = FUN_008b7c80(local_5dc);
        *(int *)(param_1 + 0x28) = iVar4 >> 0x10;
        *(undefined4 *)(iVar5 + 0xc) = local_18;
        *(undefined4 *)(iVar5 + 0x10) = local_14;
        *(undefined4 *)(iVar5 + 0x14) = local_10;
        *(undefined4 *)(iVar5 + 0x18) = local_c;
        *(int *)(iVar5 + 0x1c) = local_94;
        *(int *)(iVar5 + 0x20) = local_90;
        *(undefined1 *)(iVar5 + 8) = 1;
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      iVar4 = FUN_008b7c80(local_5dc);
      *(int *)(param_1 + 0x28) = iVar4 >> 0x10;
      iVar4 = FUN_008b7c80(local_5dc);
      *(int *)(param_1 + 0x38) = iVar4 >> 0x10;
      *(undefined1 *)(*(int *)(param_1 + 0x9c) + 8) = 0;
      iVar5 = *(int *)(iVar5 + 0xd0) - *(int *)(iVar5 + 200) >> 0x10;
      *(int *)(param_1 + 0x34) = iVar5;
      *(int *)(param_1 + 0x3c) = iVar5;
      *(undefined4 *)(param_1 + 0x48) = 0x6f75746c;
      if (*(ushort *)(param_2 + 0xe) < 0x18) {
        *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) | 0x100;
      }
      FUN_008b9570(puVar1,&local_18);
      FUN_008b94d0(puVar1,local_94,local_90);
      local_614 = *(int *)(param_1 + 0x28);
      local_610 = 0;
      FUN_008b9510(&local_614,&local_18);
      local_610 = *(int *)(param_1 + 0x34);
      *(int *)(param_1 + 0x28) = local_614 + local_94;
      local_614 = 0;
      FUN_008b9510(&local_614,&local_18);
      *(int *)(param_1 + 0x34) = local_610 + local_90;
      if (local_608 == 0) {
        iVar5 = *(int *)(param_1 + 0xa4);
        iVar4 = *(int *)(param_1 + 0xa8);
        piVar6 = *(int **)(local_5f4 + 4);
        if ((cVar3 == '\0') || (local_5bc == 0)) {
          for (iVar7 = (int)*(short *)(local_5f4 + 2); 0 < iVar7; iVar7 = iVar7 + -1) {
            lVar2 = (longlong)*piVar6 * (longlong)iVar5;
            lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
            *piVar6 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
            lVar2 = (longlong)piVar6[1] * (longlong)iVar4;
            lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
            piVar6[1] = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
            piVar6 = piVar6 + 2;
          }
        }
        lVar2 = (longlong)*(int *)(param_1 + 0x28) * (longlong)iVar5;
        lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
        local_60c = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
        local_608 = *(uint *)(param_1 + 0x34);
        *(int *)(param_1 + 0x28) = local_60c;
        lVar2 = (longlong)(int)local_608 * (longlong)iVar4;
        lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
        *(uint *)(param_1 + 0x34) =
             ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
      }
      FUN_008b9440(puVar1,&local_28);
      *(int *)(param_1 + 0x18) = local_20 - local_28;
      *(int *)(param_1 + 0x1c) = local_1c - local_24;
      *(int *)(param_1 + 0x20) = local_28;
      *(int *)(param_1 + 0x24) = local_1c;
      if ((param_4 & 0x10) != 0) {
        FUN_008b86a0((int *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x34));
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

