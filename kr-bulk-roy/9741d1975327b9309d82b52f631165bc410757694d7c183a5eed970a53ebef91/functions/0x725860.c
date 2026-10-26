
/* WARNING: Removing unreachable block (ram,0x007258d5) */

void FUN_00725860(uint *param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint *in_EAX;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  bool bVar10;
  uint local_1c [4];
  uint *local_c;
  uint *local_8;
  
  puVar6 = in_EAX + 2;
  local_8 = puVar6;
  for (; ((in_EAX != param_1 && (in_EAX[-2] == *in_EAX)) && (in_EAX[-1] == in_EAX[1]));
      in_EAX = in_EAX + -2) {
  }
  local_c = in_EAX;
  puVar5 = puVar6;
  if (puVar6 != param_2) {
    do {
      if ((*puVar6 != *in_EAX) || (puVar6[1] != in_EAX[1])) break;
      puVar6 = puVar6 + 2;
    } while (puVar6 != param_2);
    local_8 = puVar6;
    puVar5 = puVar6;
  }
  do {
    puVar7 = local_c;
LAB_007258b2:
    puVar3 = in_EAX;
    puVar4 = puVar7;
    puVar9 = puVar5;
    if (puVar6 != param_2) {
      do {
        uVar1 = puVar6[1];
        if (in_EAX[1] == 0) {
          if (uVar1 == 0) {
            bVar10 = *in_EAX < *puVar6;
            puVar7 = local_c;
            goto LAB_007258e4;
          }
LAB_007258eb:
          uVar2 = *puVar6;
          if ((uVar2 != *in_EAX) || (uVar1 != in_EAX[1])) break;
          uVar1 = puVar6[1];
          *puVar6 = *puVar5;
          puVar6[1] = puVar5[1];
          *puVar5 = uVar2;
          puVar5[1] = uVar1;
          puVar5 = puVar5 + 2;
          puVar7 = local_c;
        }
        else if (uVar1 != 0) {
          bVar10 = in_EAX[1] < uVar1;
LAB_007258e4:
          if (!bVar10) goto LAB_007258eb;
        }
        puVar6 = puVar6 + 2;
      } while (puVar6 != param_2);
      local_8 = puVar5;
      puVar4 = puVar7;
      puVar9 = puVar5;
    }
    while (puVar7 != param_1) {
      puVar8 = puVar4 + -2;
      uVar1 = puVar3[1];
      puVar5 = puVar3;
      if (puVar4[-1] == 0) {
        if (uVar1 == 0) {
          puVar7 = puVar8;
          if (puVar4[-1] != 0) {
            local_1c[0] = 0;
            puVar7 = local_1c;
          }
          bVar10 = *puVar7 < *puVar3;
          goto LAB_00725951;
        }
LAB_0072595b:
        if ((*puVar3 != *puVar8) || (puVar7 = local_c, puVar3[1] != puVar4[-1])) break;
        uVar1 = *puVar8;
        uVar2 = puVar4[-1];
        puVar5 = puVar3 + -2;
        *puVar8 = puVar3[-2];
        puVar4[-1] = puVar3[-1];
        puVar3[-1] = uVar2;
        *puVar5 = uVar1;
        puVar9 = local_8;
      }
      else if (uVar1 != 0) {
        bVar10 = puVar4[-1] < uVar1;
LAB_00725951:
        puVar7 = local_c;
        if (!bVar10) goto LAB_0072595b;
      }
      puVar7 = puVar7 + -2;
      local_c = puVar7;
      puVar3 = puVar5;
      puVar4 = puVar8;
    }
    if (puVar6 == param_2) {
      if (puVar7 == param_1) {
        *param_4 = puVar9;
        *param_3 = puVar3;
        return;
      }
      local_c = puVar7 + -2;
      in_EAX = puVar3 + -2;
      if (local_c != in_EAX) {
        uVar1 = puVar7[-1];
        uVar2 = *local_c;
        *local_c = *in_EAX;
        puVar7[-1] = puVar3[-1];
        *in_EAX = uVar2;
        puVar3[-1] = uVar1;
      }
      uVar1 = puVar3[-1];
      uVar2 = *in_EAX;
      puVar5 = puVar9 + -2;
      *in_EAX = *puVar5;
      puVar3[-1] = puVar9[-1];
      *puVar5 = uVar2;
      local_8 = puVar5;
      puVar9[-1] = uVar1;
      puVar7 = local_c;
      goto LAB_007258b2;
    }
    if (puVar7 == param_1) {
      if (puVar9 != puVar6) {
        uVar1 = puVar3[1];
        uVar2 = *puVar3;
        *puVar3 = *puVar9;
        puVar3[1] = puVar9[1];
        *puVar9 = uVar2;
        puVar9[1] = uVar1;
      }
      uVar1 = puVar6[1];
      uVar2 = *puVar6;
      *puVar6 = *puVar3;
      puVar6[1] = puVar3[1];
      *puVar3 = uVar2;
      puVar5 = puVar9 + 2;
      puVar3[1] = uVar1;
      puVar6 = puVar6 + 2;
      local_8 = puVar5;
      in_EAX = puVar3 + 2;
      goto LAB_007258b2;
    }
    uVar1 = puVar6[1];
    uVar2 = *puVar6;
    local_c = puVar7 + -2;
    *puVar6 = *local_c;
    puVar6[1] = puVar7[-1];
    *local_c = uVar2;
    puVar7[-1] = uVar1;
    puVar6 = puVar6 + 2;
    in_EAX = puVar3;
    puVar5 = puVar9;
  } while( true );
}

