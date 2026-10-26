
undefined4 * FUN_00853b30(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  uint *in_EAX;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 uVar5;
  undefined1 local_c [8];
  
  if (*(int *)(in_ECX + 8) != 0) {
    piVar2 = *(int **)(in_ECX + 4);
    if (param_2 == (int *)*piVar2) {
      if ((uint)param_2[3] <= *in_EAX) goto LAB_00853b7c;
    }
    else {
      if (param_2 == piVar2) {
        if (*(uint *)(piVar2[2] + 0xc) < *in_EAX) {
          uVar3 = FUN_006bde40(in_EAX);
          FUN_00853180(param_1,0,uVar3);
          return param_1;
        }
LAB_00853b7c:
        puVar4 = (undefined4 *)FUN_008177b0(local_c,in_EAX);
        *param_1 = *puVar4;
        return param_1;
      }
      if ((*in_EAX < (uint)param_2[3]) && (FUN_007a3230(), (uint)param_2[3] < *in_EAX)) {
        cVar1 = *(char *)(param_2[2] + 0x11);
      }
      else {
        if ((*in_EAX <= (uint)param_2[3]) ||
           ((FUN_0079c460(), param_2 != *(int **)(in_ECX + 4) && ((uint)param_2[3] <= *in_EAX))))
        goto LAB_00853b7c;
        cVar1 = *(char *)(param_2[2] + 0x11);
      }
      if (cVar1 != '\0') {
        uVar3 = FUN_006bde40(in_EAX);
        uVar5 = 0;
        goto LAB_00853b55;
      }
    }
  }
  uVar3 = FUN_006bde40(in_EAX);
  uVar5 = 1;
LAB_00853b55:
  FUN_00853180(param_1,uVar5,uVar3);
  return param_1;
}

