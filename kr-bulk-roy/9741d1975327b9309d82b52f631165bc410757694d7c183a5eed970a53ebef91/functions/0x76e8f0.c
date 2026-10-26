
void FUN_0076e8f0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  int local_28;
  int local_20;
  
  iVar5 = param_1[0x18];
  local_28 = *(int *)(iVar5 + 8);
  iVar1 = param_1[2];
  iVar2 = param_1[4];
  iVar6 = *(int *)(iVar5 + 0xc);
  local_20 = *(int *)(iVar5 + 0x10);
  iVar5 = *(int *)(iVar5 + 0x14);
  iVar3 = param_1[3];
  iVar4 = param_1[5];
  switch(*(undefined4 *)(in_ECX + 8)) {
  case 0x12d:
    iVar5 = 0;
    local_28 = iVar1 - iVar2;
    iVar6 = iVar4 - iVar3;
    local_20 = 0;
    break;
  case 0x12e:
    local_28 = iVar1 - iVar2;
    local_20 = 0;
    iVar5 = (((iVar5 - iVar6) - iVar4) + iVar3) / 2;
    goto LAB_0076eaa6;
  case 0x12f:
    iVar6 = iVar5 - iVar6;
    local_28 = iVar1 - iVar2;
    local_20 = 0;
    iVar5 = iVar6 + (iVar3 - iVar4);
    break;
  case 0x130:
    local_28 = local_20 - local_28;
    local_20 = (iVar2 - iVar1) + local_28;
    iVar5 = 0;
    iVar6 = iVar4 - iVar3;
    break;
  case 0x131:
    local_28 = local_20 - local_28;
    local_20 = (iVar2 - iVar1) + local_28;
    iVar5 = (((iVar5 - iVar6) - iVar4) + iVar3) / 2;
    iVar6 = iVar5 + (iVar4 - iVar3);
    break;
  case 0x132:
    local_28 = local_20 - local_28;
    iVar6 = iVar5 - iVar6;
    local_20 = (iVar2 - iVar1) + local_28;
    iVar5 = iVar6 + (iVar3 - iVar4);
    break;
  case 0x133:
    iVar6 = 0;
    local_20 = iVar2 - iVar1;
    iVar5 = iVar3 - iVar4;
    local_28 = 0;
    break;
  case 0x134:
    iVar5 = iVar3 - iVar4;
    local_28 = (((local_20 - local_28) - iVar2) + iVar1) / 2;
    local_20 = (iVar2 - iVar1) + local_28;
    iVar6 = 0;
    break;
  case 0x135:
    local_20 = local_20 - local_28;
    iVar5 = iVar3 - iVar4;
    local_28 = (iVar1 - iVar2) + local_20;
    iVar6 = 0;
    break;
  case 0x136:
    local_28 = 0;
    local_20 = iVar2 - iVar1;
    goto LAB_0076ea68;
  case 0x137:
    local_28 = (((local_20 - local_28) - iVar2) + iVar1) / 2;
    local_20 = (iVar2 - iVar1) + local_28;
LAB_0076ea68:
    iVar5 = iVar5 - iVar6;
    iVar6 = iVar5 + (iVar4 - iVar3);
    break;
  case 0x138:
    local_20 = local_20 - local_28;
    local_28 = (iVar1 - iVar2) + local_20;
    iVar5 = iVar5 - iVar6;
LAB_0076eaa6:
    iVar6 = iVar5 + (iVar4 - iVar3);
    break;
  default:
    goto switchD_0076e958_default;
  }
  (**(code **)(*param_1 + 0xbc))(local_28,iVar5,local_20,iVar6);
switchD_0076e958_default:
  return;
}

