
void FUN_00725530(int *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  int *in_EAX;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *local_c;
  int *local_8;
  
  piVar7 = in_EAX + 2;
  for (; ((in_EAX != param_1 && (in_EAX[-2] == *in_EAX)) && (in_EAX[-1] == in_EAX[1]));
      in_EAX = in_EAX + -2) {
  }
  piVar6 = in_EAX;
  piVar3 = piVar7;
  local_8 = in_EAX;
  if (piVar7 != param_2) {
    do {
      piVar3 = piVar7;
      if ((*piVar7 != *in_EAX) || (piVar7[1] != in_EAX[1])) break;
      piVar7 = piVar7 + 2;
      piVar3 = piVar7;
    } while (piVar7 != param_2);
  }
joined_r0x00725583:
  do {
    piVar5 = piVar6;
    if (piVar3 == param_2) {
joined_r0x007255bf:
      while (piVar5 != param_1) {
        local_c = piVar6 + -2;
        cVar4 = FUN_0071c4a0(local_c);
        piVar8 = in_EAX;
        if (cVar4 == '\0') {
          piVar5 = local_8;
          if ((*in_EAX != *local_c) || (in_EAX[1] != piVar6[-1])) break;
          iVar1 = piVar6[-1];
          iVar2 = *local_c;
          piVar8 = in_EAX + -2;
          *local_c = *piVar8;
          piVar6[-1] = in_EAX[-1];
          *piVar8 = iVar2;
          in_EAX[-1] = iVar1;
        }
        local_8 = local_8 + -2;
        piVar6 = local_c;
        in_EAX = piVar8;
        piVar5 = local_8;
      }
      if (piVar3 == param_2) {
        if (piVar5 == param_1) {
          *param_3 = in_EAX;
          *param_4 = piVar7;
          return;
        }
        piVar6 = piVar5 + -2;
        piVar8 = in_EAX + -2;
        if (piVar6 != piVar8) {
          iVar1 = piVar5[-1];
          iVar2 = *piVar6;
          *piVar6 = *piVar8;
          piVar5[-1] = in_EAX[-1];
          *piVar8 = iVar2;
          in_EAX[-1] = iVar1;
        }
        iVar1 = in_EAX[-1];
        iVar2 = *piVar8;
        piVar5 = piVar7 + -2;
        *piVar8 = *piVar5;
        in_EAX[-1] = piVar7[-1];
        *piVar5 = iVar2;
        piVar7[-1] = iVar1;
        piVar7 = piVar5;
        local_8 = piVar6;
        in_EAX = piVar8;
      }
      else if (piVar5 == param_1) {
        if (piVar7 != piVar3) {
          iVar1 = in_EAX[1];
          iVar2 = *in_EAX;
          *in_EAX = *piVar7;
          in_EAX[1] = piVar7[1];
          *piVar7 = iVar2;
          piVar7[1] = iVar1;
        }
        iVar1 = piVar3[1];
        iVar2 = *piVar3;
        *piVar3 = *in_EAX;
        piVar3[1] = in_EAX[1];
        *in_EAX = iVar2;
        piVar7 = piVar7 + 2;
        in_EAX[1] = iVar1;
        in_EAX = in_EAX + 2;
        piVar6 = piVar5;
        piVar3 = piVar3 + 2;
      }
      else {
        iVar1 = piVar3[1];
        iVar2 = *piVar3;
        piVar6 = piVar5 + -2;
        *piVar3 = *piVar6;
        piVar3[1] = piVar5[-1];
        *piVar6 = iVar2;
        piVar5[-1] = iVar1;
        piVar3 = piVar3 + 2;
        local_8 = piVar6;
      }
      goto joined_r0x00725583;
    }
    cVar4 = FUN_0071c4a0(in_EAX);
    piVar6 = local_8;
    if (cVar4 == '\0') {
      iVar1 = *piVar3;
      piVar5 = local_8;
      if ((iVar1 != *in_EAX) || (iVar2 = piVar3[1], iVar2 != in_EAX[1])) goto joined_r0x007255bf;
      *piVar3 = *piVar7;
      piVar3[1] = piVar7[1];
      *piVar7 = iVar1;
      piVar7[1] = iVar2;
      piVar7 = piVar7 + 2;
    }
    piVar3 = piVar3 + 2;
  } while( true );
}

