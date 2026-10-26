
undefined4 FUN_0053c230(ushort param_1)

{
  int iVar1;
  ushort uVar2;
  int in_EAX;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  int local_c;
  uint local_8;
  
  uVar2 = param_1;
  uVar3 = *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 1;
  uVar5 = 0;
  if (uVar3 != 0) {
    puVar6 = *(ushort **)(in_EAX + 4);
    do {
      if (*puVar6 == param_1) {
        puVar6 = *(ushort **)(in_EAX + 4) + uVar5;
        FID_conflict__memcpy(puVar6,puVar6 + 1,(*(int *)(in_EAX + 8) - (int)(puVar6 + 1) >> 1) * 2);
        *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + -2;
        local_8 = (uint)uVar2;
        iVar4 = FUN_0041a4d0();
        FUN_00826280(&local_8);
        if ((local_c != *(int *)(iVar4 + 0x5ecc)) && (**(ushort **)(iVar4 + 0x5ed8) != param_1)) {
          iVar1 = *(int *)(local_c + 0x10);
          if (iVar1 != 0) {
            FUN_00539630();
            FUN_0089120c(iVar1);
          }
          FUN_007b6890(iVar4 + 0x5ec8,&param_1,local_c);
        }
        return 1;
      }
      uVar5 = uVar5 + 1;
      puVar6 = puVar6 + 1;
    } while (uVar5 < uVar3);
  }
  return 0;
}

