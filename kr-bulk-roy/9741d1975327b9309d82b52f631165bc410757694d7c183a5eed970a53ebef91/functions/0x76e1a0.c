
void FUN_0076e1a0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  int local_1c;
  
  iVar4 = param_1[0x18];
  iVar1 = *(int *)(iVar4 + 0xc);
  iVar2 = *(int *)(iVar4 + 8);
  local_1c = *(int *)(iVar4 + 0x14);
  iVar4 = *(int *)(iVar4 + 0x10);
  switch(*(undefined4 *)(in_ECX + 8)) {
  case 1:
    iVar4 = param_1[4] - param_1[2];
    iVar5 = 0;
    iVar3 = 0;
    local_1c = local_1c - iVar1;
    break;
  case 2:
    iVar4 = iVar4 - iVar2;
    iVar5 = (param_1[2] - param_1[4]) + iVar4;
    iVar3 = 0;
    local_1c = local_1c - iVar1;
    break;
  case 3:
    iVar4 = iVar4 - iVar2;
    iVar5 = 0;
    iVar3 = 0;
    local_1c = param_1[5] - param_1[3];
    break;
  case 4:
    local_1c = local_1c - iVar1;
    iVar4 = iVar4 - iVar2;
    iVar5 = 0;
    iVar3 = (param_1[3] - param_1[5]) + local_1c;
    break;
  case 5:
    iVar4 = iVar4 - iVar2;
    iVar5 = 0;
    iVar3 = 0;
    local_1c = local_1c - iVar1;
    break;
  default:
    goto switchD_0076e1ea_caseD_6;
  case 0x65:
    iVar4 = param_1[4] - param_1[2];
    iVar5 = 0;
    iVar3 = 0;
    local_1c = param_1[5] - param_1[3];
    break;
  case 0x66:
    iVar3 = 0;
    iVar5 = ((param_1[2] - param_1[4]) - iVar2) + iVar4;
    iVar4 = iVar4 - iVar2;
    local_1c = param_1[5] - param_1[3];
    break;
  case 0x67:
    iVar4 = param_1[4] - param_1[2];
    iVar5 = 0;
    iVar3 = ((param_1[3] - param_1[5]) - iVar1) + local_1c;
    local_1c = local_1c - iVar1;
    break;
  case 0x68:
    iVar5 = ((param_1[2] - param_1[4]) - iVar2) + iVar4;
    iVar4 = iVar4 - iVar2;
    iVar3 = ((param_1[3] - param_1[5]) - iVar1) + local_1c;
    local_1c = local_1c - iVar1;
    break;
  case 0x69:
    iVar5 = (((param_1[2] - param_1[4]) - iVar2) + iVar4) / 2;
    iVar3 = 0;
    local_1c = param_1[5] - param_1[3];
    iVar4 = iVar5 + (param_1[4] - param_1[2]);
    break;
  case 0x6a:
    iVar5 = (((param_1[2] - param_1[4]) - iVar2) + iVar4) / 2;
    iVar4 = (param_1[4] - param_1[2]) + iVar5;
    goto LAB_0076e363;
  case 0x6b:
    iVar5 = (((param_1[2] - param_1[4]) - iVar2) + iVar4) / 2;
    iVar4 = (param_1[4] - param_1[2]) + iVar5;
    iVar3 = ((param_1[3] - param_1[5]) - iVar1) + local_1c;
    local_1c = local_1c - iVar1;
    break;
  case 0x6c:
    iVar5 = 0;
    iVar4 = param_1[4] - param_1[2];
    goto LAB_0076e363;
  case 0x6d:
    iVar5 = ((param_1[2] - param_1[4]) - iVar2) + iVar4;
    iVar4 = iVar4 - iVar2;
LAB_0076e363:
    iVar3 = (((param_1[3] - param_1[5]) - iVar1) + local_1c) / 2;
    local_1c = (param_1[5] - param_1[3]) + iVar3;
  }
  (**(code **)(*param_1 + 0xbc))(iVar5,iVar3,iVar4,local_1c);
switchD_0076e1ea_caseD_6:
  return;
}

