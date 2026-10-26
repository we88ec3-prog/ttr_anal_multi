
uint FUN_008caef0(code *param_1,uint param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  int in_EAX;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *unaff_EDI;
  uint local_14;
  int *local_8;
  
  local_8 = (int *)unaff_EDI[10];
  piVar1 = (int *)unaff_EDI[0xd];
  iVar3 = piVar1[in_EAX * 2 + 1];
  if (((int)param_2 <= piVar1[1]) && (iVar3 <= (int)param_3)) {
    uVar4 = -unaff_EDI[1] & piVar1[1];
    if ((int)param_3 < (int)uVar4) {
      uVar4 = param_3;
    }
    local_14 = param_2;
    if (((int)param_2 <= iVar3) &&
       (local_14 = unaff_EDI[1] + -1 + iVar3 & -unaff_EDI[1], param_2 = local_14,
       (ushort)((ushort)iVar3 & *(short *)(unaff_EDI + 1) - 1U) == 0)) {
      if (*(char *)((int)unaff_EDI + 0x57) != '\0') {
        local_8 = local_8 + -1;
        *(undefined1 *)((int)unaff_EDI + 0x57) = 0;
      }
      *local_8 = piVar1[in_EAX * 2];
      local_8 = local_8 + 1;
      param_2 = local_14 + unaff_EDI[1];
    }
    if (*(char *)((int)unaff_EDI + 0x56) != '\0') {
      *(int *)(unaff_EDI[0x16] + 0x14) = (int)local_14 >> ((byte)*unaff_EDI & 0x1f);
      *(undefined1 *)((int)unaff_EDI + 0x56) = 0;
    }
    if ((int)param_2 <= (int)uVar4) {
      piVar5 = piVar1;
      if ((int *)unaff_EDI[9] <= local_8 + ((int)(uVar4 - param_2) >> ((byte)*unaff_EDI & 0x1f)) + 1
         ) {
        unaff_EDI[0xb] = 0x62;
        unaff_EDI[10] = local_8;
        return CONCAT31((int3)((uint)(in_EAX * 8) >> 8),1);
      }
      do {
        if ((int)uVar4 < (int)param_2) break;
        *(undefined1 *)((int)unaff_EDI + 0x57) = 0;
        uVar2 = piVar5[1];
        if ((int)param_2 < (int)uVar2) {
          iVar3 = uVar2 - piVar5[in_EAX * 2 + 1];
          if (iVar3 < (int)unaff_EDI[4]) {
            *local_8 = (int)((*piVar5 - piVar5[in_EAX * 2]) * (param_2 - piVar5[in_EAX * 2 + 1])) /
                       iVar3 + piVar5[in_EAX * 2];
            local_8 = local_8 + 1;
            piVar5 = piVar5 + in_EAX * -2;
            param_2 = param_2 + unaff_EDI[1];
          }
          else {
            (*param_1)(piVar5);
            piVar5 = piVar5 + in_EAX * 2;
          }
        }
        else {
          if (uVar2 == param_2) {
            *(undefined1 *)((int)unaff_EDI + 0x57) = 1;
            *local_8 = *piVar5;
            local_8 = local_8 + 1;
            param_2 = param_2 + unaff_EDI[1];
          }
          piVar5 = piVar5 + in_EAX * -2;
        }
      } while (piVar1 <= piVar5);
    }
  }
  unaff_EDI[0xd] = unaff_EDI[0xd] + in_EAX * -8;
  unaff_EDI[10] = local_8;
  return in_EAX * 8 & 0xffffff00;
}

