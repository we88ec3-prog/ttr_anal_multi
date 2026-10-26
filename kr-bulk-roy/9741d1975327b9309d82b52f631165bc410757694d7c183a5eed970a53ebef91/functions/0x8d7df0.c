
int FUN_008d7df0(undefined4 param_1,undefined4 *param_2,int param_3,int param_4,undefined4 param_5)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_1c;
  undefined4 local_18;
  undefined4 *local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  piVar4 = param_2 + 0x7d;
  *piVar4 = 0;
  *param_2 = 1;
  iVar5 = FUN_008b8ff0(param_2[0x18],"postscript-cmaps");
  param_2[0x79] = iVar5;
  local_8 = FUN_008b8fc0(*(undefined4 *)(param_2[0x18] + 4),"psaux");
  param_2[0x7a] = local_8;
  if (local_8 == 0) {
    return 0xb;
  }
  iVar6 = FUN_008d7b90(param_2);
  if ((iVar6 == 0) && (-1 < param_3)) {
    if (0 < param_3) {
      return 6;
    }
    param_2[2] = param_2[2] | 0x211;
    param_2[4] = param_2[0x68];
    param_2[9] = 0;
    param_2[1] = 0;
    if (*(char *)(param_2 + 0x27) != '\0') {
      param_2[2] = param_2[2] | 4;
    }
    param_2[2] = param_2[2] | 0x800;
    pcVar8 = (char *)param_2[0x24];
    param_2[5] = pcVar8;
    param_2[6] = "Regular";
    if (pcVar8 == (char *)0x0) {
      if (param_2[0x5b] != 0) {
        param_2[5] = param_2[0x5b];
      }
    }
    else {
      pcVar7 = (char *)param_2[0x23];
      if (pcVar7 != (char *)0x0) {
        cVar1 = *pcVar7;
        while (cVar1 != '\0') {
          cVar2 = *pcVar8;
          if (cVar1 == cVar2) {
            pcVar8 = pcVar8 + 1;
LAB_008d7ee7:
            pcVar7 = pcVar7 + 1;
          }
          else {
            if ((cVar1 == ' ') || (cVar1 == '-')) goto LAB_008d7ee7;
            if ((cVar2 != ' ') && (cVar2 != '-')) {
              if (*pcVar8 == '\0') {
                param_2[6] = pcVar7;
              }
              break;
            }
            pcVar8 = pcVar8 + 1;
          }
          cVar1 = *pcVar7;
        }
      }
    }
    local_2c = param_2[0x7c];
    local_30 = param_2[0x7b];
    param_2[7] = 0;
    param_2[8] = 0;
    local_34 = 1;
    if (param_4 != 0) {
      local_34 = 0x11;
      local_1c = param_4;
      local_18 = param_5;
    }
    iVar6 = FUN_008bd6d0(*(undefined4 *)(param_2[0x18] + 4),&local_34,0,piVar4);
    if (iVar6 == 0) {
      FUN_008ba690(*(undefined4 *)(*piVar4 + 0x58));
      iVar3 = *piVar4;
      param_2[0xd] = *(undefined4 *)(iVar3 + 0x34);
      param_2[0xe] = *(undefined4 *)(iVar3 + 0x38);
      param_2[0xf] = *(undefined4 *)(iVar3 + 0x3c);
      param_2[0x10] = *(undefined4 *)(iVar3 + 0x40);
      *(undefined2 *)(param_2 + 0x11) = *(undefined2 *)(iVar3 + 0x44);
      *(undefined2 *)((int)param_2 + 0x46) = *(undefined2 *)(iVar3 + 0x46);
      *(undefined2 *)(param_2 + 0x12) = *(undefined2 *)(iVar3 + 0x48);
      *(undefined2 *)((int)param_2 + 0x4a) = *(undefined2 *)(iVar3 + 0x4a);
      *(undefined2 *)(param_2 + 0x13) = *(undefined2 *)(iVar3 + 0x4c);
      *(undefined2 *)((int)param_2 + 0x4e) = *(undefined2 *)(iVar3 + 0x4e);
      *(undefined2 *)(param_2 + 0x14) = *(undefined2 *)((int)param_2 + 0x9e);
      *(undefined2 *)((int)param_2 + 0x52) = *(undefined2 *)(param_2 + 0x28);
      param_2[3] = 0;
      if (param_2[0x26] != 0) {
        param_2[3] = 1;
      }
      if ((*(byte *)(iVar3 + 0xc) & 2) != 0) {
        param_2[3] = param_2[3] | 2;
      }
      if ((*(byte *)(iVar3 + 8) & 0x20) != 0) {
        param_2[2] = param_2[2] | 0x20;
      }
      if (iVar5 != 0) {
        piVar4 = *(int **)(local_8 + 0x14);
        local_14 = param_2;
        local_c = 0x10003;
        local_10 = 0x756e6963;
        iVar6 = FUN_008bcc30(piVar4[3],0,&local_14,0);
        if ((iVar6 == 0) || ((char)iVar6 == -0x5d)) {
          iVar6 = 0;
          switch(param_2[0x5c]) {
          case 1:
            local_10 = 0x41444243;
            local_c = 0x20007;
            iVar5 = piVar4[2];
            break;
          case 2:
            local_10 = 0x41444f42;
            local_c = 7;
            iVar5 = *piVar4;
            break;
          case 3:
            local_10 = 0x6c617431;
            local_c = 0x30007;
            iVar5 = piVar4[3];
            break;
          case 4:
            local_10 = 0x41444245;
            local_c = 0x10007;
            iVar5 = piVar4[1];
            break;
          default:
            goto switchD_008d8062_default;
          }
          if (iVar5 != 0) {
            iVar6 = FUN_008bcc30(iVar5,0,&local_14,0);
          }
        }
      }
    }
  }
switchD_008d8062_default:
  return iVar6;
}

