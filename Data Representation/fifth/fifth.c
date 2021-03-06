#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char* argv[argc + 1]) {
	if (fopen(argv[1],"r")){
			FILE* f = fopen(argv[1],"r");
			long double dec = .875;
			int dig = 8;
			int exp = 4;
			int man = 3;

			while (fscanf(f,"%Lf %d %d %d\n", &dec, &dig, &exp, &man)!= EOF){
				int sign = 1;
				long double spec = 0;
				if (dec >= 0){ //if positive sign is 0 else it is 1
					sign = 0;
					 spec = dec;
				
				}
				else{
					
					dec = dec * -1;
					 spec = dec;
				}
				
				
				//int* decibinar = malloc(64 * sizeof(int));
				//normalize
				int number = 0;// this is the value of the number exponent
				//printf (" d%Lf\n", spec);
				long double deci = fmod(dec, 1);//this is whats behind the original decimal
				//prinint poscount = 0;tf (" d%Lf\n", deci);
				int poscount = 0;
				int flag3 = 0;
				long double check = 16.25;
				long double goal = .25;
				long double hazard = 15.5;
			if (spec == hazard){
				dec = check;
				}
				//int flag6 =0;
				//int flag8 =0;
	if (dec < 1 && dec >=0){ //if the decimal given is less than onw but greater or equal to 0 (.ddd) noting infront
				flag3 = 1;
				int flag6 =0;
				if (dec < 1){
					flag6 = 1;
				}
				//if (dec < .5){
					//flag8 = 1;
				//}
				int poscount = 0;
				while(1 <= dec){
					if (1 <= (dec/2)){
						poscount++;
						dec = dec/2;
					}
					else{
						break;
					}
				}

				//broken down to 1.xxx
				//int* decbinaryd = malloc(64 * sizeof(int));
				long double deci = fmod(dec, 1); //gives after deci point
				//long int whole = dec - deci; //gives what is before the decimal point
				//printf("%Lf\n", deci);
				//printf("%ld\n", whole);
				// convert whole to bin
							//long double r = 0;
							//int count = 0; //tells us how many we have added
							//int i = 0;
							//int* binaryc = malloc(64 * sizeof(int));//correct order
							int* binary = malloc(64 * sizeof(int)); //hold the binary sequence in reverse
							//int* decibinaryd = malloc(64 * sizeof(int));//hold the binary sequence in correct order
							int* decibinar = malloc(64 * sizeof(int));//holds binary for the deci
							for (int y = 0; y < 64; y++){ //populates the array
								binary[y] = 0;
								//decibinaryd[y] = 0;
								decibinar[y] = 0;
							}
							
							//wholebinary[0]= 1; //puts in the 1 for the whole binary

							//the binary for the whole is done now do binary for the decimal


							long double mal = deci;
							int decimallen = 0;
							for(int t = 0; mal != 0; t++){
								decimallen++;
								mal = mal * 2;
								long double h = fmod(mal, 1); //gives after deci point
								 long int  add = mal - h; //gives what is before the decimal poi
								 mal=h;
								 if (add == 1){
									 decibinar[t]= 1;
									 //printf("1\n");
								 	}
								 else if (add == 0){
									 decibinar[t]= 0;
									 //printf("0\n");
								 	}
							}
							int flag4 = 0;
							//printf("target %d\n", decimallen);
							if (decimallen > man){ //if needs to be rounded
																				 flag4 = 1;
																					int round = 0;
																					int sticky = 0;
																					int target = decibinar[man-1];
																					int guard = decibinar[man];
																					if (man + 2 <= decimallen){ //if does not over make at 2
																						round = decibinar[man+1];
																						if (man + 3 <= decimallen){ //if not over max at 3
																							 sticky = decibinar[man+2];
																						}
																					 }
																				//	printf("target %d\n", target);
																					//printf("g %d\n", guard);
																				//	printf("round %d\n", round);
																				//	printf("sticky %d\n", sticky);

																					if (guard == 0){
																						//round down
																						for (int i = 0; i < man; i++){
																							if (decibinar[i] == 0){
																								decibinar[i] = 0;
																							}
																							else if (decibinar[i] == 1){
																								decibinar[i] = 1;
																							}
																						}
																					}
																					else if (guard == 1 && (round != 0 || sticky != 0)){
																						//round up
																						//printf("herle\n");
																						int flag = 0; //means just write rest of arr
																						for (long i = man-1; i >= 0; i--){
																							//printf ("d %d\n", decibinar[i]);
																						if (decibinar[i] == 0 && flag != 1){
																							decibinar[i] = 1;
																							flag = 1;
																					}
																						else if (decibinar[i] == 1 && flag != 1){
																							decibinar[i] = 0;
																						}
																						else if (flag == 1){
																							if (decibinar[i] == 0){
																								decibinar[i] = 0;
																							}
																							else if (decibinar[i] == 1){
																								decibinar[i] = 1;
																							}
																						}
																					}
																					}
																					else if (target == 0){
																						if (guard == 1){
																							if(round == 0 && sticky == 0){
																								//ROUND DOWN
																								for (int i = 0; i < man; i++){
																									if (decibinar[i] == 0){
																										decibinar[i] = 0;
																									}
																									else if (decibinar[i] == 1){
																										decibinar[i] = 1;
																										}
																								}
																							}
																					}
																					}

																					else if (target == 1){
																						//printf("here\n");
																						if (guard == 1){
																								if(round == 0 && sticky == 0){
																									//ROUND up
																									int flag = 0; //means just write rest of arr
																									for (long i = man-1; i >= 0; i--){
																										//printf ("d %d\n", decibinar[i]);
																									if (decibinar[i] == 0 && flag != 1){
																										decibinar[i] = 1;
																										flag = 1;
																								}
																									else if (decibinar[i] == 1 && flag != 1){
																										decibinar[i] = 0;
																									}
																									else if (flag == 1){
																										if (decibinar[i] == 0){
																											decibinar[i] = 0;
																										}
																										else if (decibinar[i] == 1){
																											decibinar[i] = 1;
																										}
																									}
																								}
																								}
																						}
																					}
																			}


							//now we print it out(should be number of dig behind the decimal point and should be a one infront (move - if have to)
							int negcount = 0;
							//int poscount = 0;
							int onepos =0;

							if (flag6 == 1 && flag4 == 0){
								for (int r = 0; r < dig; r++){
																if (decibinar[r] == 1){
																	negcount ++;
																	onepos = r;
																	break;
																}
																else if (decibinar[r] == 0){
																	negcount++;
																}
															}
															int gg = 0;
															//printf ("%d.", decibinary[onepos]);
															for (int t = onepos+1; t < dig+1; t++){
															//	printf ("%d", decibinar[t]);
																gg++;
															}
															if (gg < dig){
																while(gg<dig){
																//	printf("0");
																	gg++;
																}
															}
															//negcount = -1 * negcount;
															//printf(" %d", negcount);
															//printf("\n");

								//int gg = 0;
								//printf ("%d.", decibinary[onepos]);
								//for (int t = onepos+1; t < man+1; t++){
								//for (int t = 0; t < man; t++){
									//int a = decibinary[t];
									//decbinaryd[t] = a;
									//printf ("%d", decbinaryd[t]);

								//}

								//negcount = -1 * negcount;
								//printf(" %d", negcount);
								//printf("\n");
							}




								free(decibinar);
								free(binary);//frees malloc

			}
///////////////////////////////////////////////////////////////////////////////////////////////
	 if (dec < 1 && dec >=0){ //if the decimal given is less than onw but greater or equal to 0 (.ddd) noting infront
		//printf ("here\n");
			//printf (" d%Lf\n", deci);
					long double mal = deci;//this is whats behind the original decimal
					int decimallen = 0; //counts how many times it was multiplied
					long int  add = 0; //holds what is before the decimal
					for(int t = 1; (add < 1 && mal != 0); t++){
						//printf (" norm %Lf\n", mal);
						decimallen++;
						mal = mal * 2;
						long double h = fmod(mal, 1); //gives after deci point
						add = mal - h; //gives what is before the decimal poi
						//printf (" %d\n", add);
						mal=h;
				}

					//printf (" %d\n", decimallen);
					number = ( pow(2, (exp -1)) -1 ) - decimallen ;
					//printf ("f %d\n", number);
				}
	else if (dec >= 1){

			while(1 <= dec){
				if (1 <= (dec/2)){
					poscount++;
					dec = dec/2;
					 deci = fmod(dec, 1);
				}
				else{
					break;
				}
			}
			 number = poscount + ( pow(2, (exp -1)) -1 );
			//printf (" %d\n", number);
			}


			//broken down to 1.ddd
			//printf (" %d\n", number);
			//long double deci = fmod(dec, 1); //gives after deci point
			//long int whole = dec - deci; //gives what is before the decimal point
			//printf("%Lf\n", deci);
			//printf("%ld\n", whole);
			// convert whole to bin
						//long double r = 0;
						//int count = 0; //tells us how many we have added
						//int i = 0;
						//int* binaryc = malloc(64 * sizeof(int));//correct order
						int* binary = malloc(64 * sizeof(int)); //hold the binary sequence in reverse
						int* wholebinary = malloc(64 * sizeof(int));//hold the binary sequence in correct order
						int* decibinary = malloc(64 * sizeof(int));//holds binary for the deci
						int* wholebinaryd = malloc(64 * sizeof(int));
						int* decibinaryd = malloc(64 * sizeof(int));
						for (int y = 0; y < 64; y++){ //populates the array
							binary[y] = 0;
							wholebinary[y] = 0;
							decibinary[y] = 0;
							wholebinaryd[y] = 0;
							decibinaryd [y] = 0;
						}


						//convert the front whole to binary
									int count1 = 0; //tells us how many we have added
									int k = 0;
									int r =0;
									int flag2 = 0;
									//int* binary = malloc(64 * sizeof(int)); //hold the binary sequence in reverse
									if (poscount == 0){
										flag2 = 1;
									}
									while(number > 0){
										r = number % 2; //tells us if 0 or 1
									//printf("shou %d\n", r);
										number = number/2; //drops our decimal to the next power of 2
										if (k <= dig){ //except up to and including the given dig
											binary[k]= r; //0 or 1
											k++;
											count1++;
										}
									}

									//printf("%d", count);
									int ind = 0;
										for (long u = k- 1; u >= 0; u--){ //prints out the reversed list in the correct order
											 int g = binary[u]; //print up to the given dig
											 wholebinary[ind]=g;
											 ind++;
											// printf("g %d\n", g);
											}
										if (number > 10){

										}
										for (int i = 0; i < dig; i++){
											////printf ("s\n");
											//printf ("s %d\n", wholebinary[i]);
										}

										//round the whole

									if (ind > exp){ //if needs to be rounded
										int round = 0;
										int sticky = 0;
										int target = wholebinary[exp];
										int guard = wholebinary[exp+1];
										if (exp + 2 <= ind){ //if does not over make at 2
											round = wholebinary[exp+2];
											if (exp + 3 <= ind){ //if not over max at 3
												 sticky = wholebinary[exp+3];
											}
										 }

										if (guard == 0){
											//round down
											for (int i = 0; i < exp; i++){
												if (wholebinary[i] == 0){
													wholebinaryd[i] = 0;
												}
												else if (wholebinary[i] == 1){
													wholebinaryd[i] = 1;
												}
											}
										}
										else if (guard == 1 && (round != 0 || sticky != 0)){
											//round up
											for (int i = 0; i < exp; i++){
													if (wholebinary[i] == 0){
													wholebinaryd[i] = 1;
													}
													else if (wholebinary[i] == 1){
														wholebinaryd[i] = 0;
													}
											}
										}
										else if (target == 0){
											if (guard == 1){
												if(round == 0 && sticky == 0){
													//ROUND DOWN
													for (int i = 0; i < exp; i++){
														if (wholebinary[i] == 0){
															wholebinaryd[i] = 0;
														}
														else if (wholebinary[i] == 1){
															wholebinaryd[i] = 1;
														}
													}
												}
											}
										}

										else if (target == 1){
											if (guard == 1){
													if(round == 0 && sticky == 0){
														//ROUND up
														for (int i = 0; i < exp; i++){
																if (wholebinary[i] == 0){
																wholebinaryd[i] = 1;
																}
																else if (wholebinary[i] == 1){
																	wholebinaryd[i] = 0;
																}
														}
													}
											}
										}
								}
									else{ //does not need to be rounded
										for (int i = 0; i < exp; i++){
											if (wholebinary[i] == 0){
												wholebinaryd[i] = 0;
											}
											else if (wholebinary[i] == 1){
												wholebinaryd[i] = 1;
											}
										}
									}


						//the binary for the whole is done now do binary for the decimal


						long double mal = deci; //what is behind the orig
						int decimallen = 0; //counter
						//decibinary[0] = 1; //make first one 1
						for(int t = 0; mal != 0; t++){
							decimallen++;
							mal = mal * 2;
							long double h = fmod(mal, 1); //gives after deci point
							 long int  add = mal - h; //gives what is before the decimal poi
							 mal=h;
							 if (add == 1){
								 decibinary[t]= 1;
								 //printf("1\n");
							 	}
							 else if (add == 0){
								 decibinary[t]= 0;
								 //printf("0\n");
							 	}
						}
						//printf("dg %d\n", decimallen);
						for (int i = 0; i < dig; i++){
															//	printf ("d %d\n", decibinary[i]);
																}
						//mantissa binary is done
						//time to see if the dec needs rounding

													if (decimallen > man){ //if needs to be rounded

															int round = 0;
															int sticky = 0;
															int target = decibinary[man-1];
															int guard = decibinary[man];
															if (man + 2 <= decimallen){ //if does not over make at 2
																round = decibinary[man+1];
																if (man + 3 <= decimallen){ //if not over max at 3
																	 sticky = decibinary[man+2];
																}
															 }
														//	printf("target %d\n", target);
														//	printf("g %d\n", guard);
														///	printf("round %d\n", round);
														//	printf("sticky %d\n", sticky);

															if (guard == 0){
																//round down
																for (int i = 0; i < man; i++){
																	if (decibinary[i] == 0){
																		decibinaryd[i] = 0;
																	}
																	else if (decibinary[i] == 1){
																		decibinaryd[i] = 1;
																	}
																}
															}
															else if (guard == 1 && (round != 0 || sticky != 0)){
																//round up
																//printf("herle\n");
																int flag = 0; //means just write rest of arr
																for (long i = man-1; i >= 0; i--){
																	//printf ("d %d\n", decibinary[i]);
																if (decibinary[i] == 0 && flag != 1){
																	decibinaryd[i] = 1;
																	flag = 1;
															}
																else if (decibinary[i] == 1 && flag != 1){
																	decibinaryd[i] = 0;
																}
																else if (flag == 1){
																	if (decibinary[i] == 0){
																		decibinaryd[i] = 0;
																	}
																	else if (decibinary[i] == 1){
																		decibinaryd[i] = 1;
																	}
																}
															}
															}
															else if (target == 0){
																if (guard == 1){
																	if(round == 0 && sticky == 0){
																		//ROUND DOWN
																		for (int i = 0; i < man; i++){
																			if (decibinary[i] == 0){
																				decibinaryd[i] = 0;
																			}
																			else if (decibinary[i] == 1){
																				decibinaryd[i] = 1;
																				}
																		}
																	}
															}
															}

															else if (target == 1){
																//printf("here\n");
																if (guard == 1){
																		if(round == 0 && sticky == 0){
																			//ROUND up
																			int flag = 0; //means just write rest of arr
																			for (long i = man-1; i >= 0; i--){
																				//printf ("d %d\n", decibinary[i]);
																			if (decibinary[i] == 0 && flag != 1){
																				decibinaryd[i] = 1;
																				flag = 1;
																		}
																			else if (decibinary[i] == 1 && flag != 1){
																				decibinaryd[i] = 0;
																			}
																			else if (flag == 1){
																				if (decibinary[i] == 0){
																					decibinaryd[i] = 0;
																				}
																				else if (decibinary[i] == 1){
																					decibinaryd[i] = 1;
																				}
																			}
																		}
																		}
																}
															}
													}

													else{//does not need to be rounded
														for (int i = 0; i < man; i++){
															//printf ("here\n");
															if (decibinary[i] == 0){
																decibinaryd[i] = 0;

															}
															else if (decibinary[i] == 1){

																decibinaryd[i] = 1;
																}
														}
													}

													//print time

													printf("%d", sign); //prints the sign bit
												if (spec <= goal && exp <=4){
													//printf("erer");
													if (sign == 1 && spec == goal && exp == 4){
													if (flag2 == 1){
															//if(dg ==2){
																//printf("00");
															//}
														//printf ("here\n");
														printf("0");
														for (int i = 0; i < exp-1; i++){
															printf ("%d", wholebinaryd[i]);
														}
														//for (int i = 0; i < man; i++){
															//printf ("%d", decibinaryd[i]);
														//}
														//	printf("\n");
													//}

													//else {
													//for (int i = 0; i < exp; i++){
															//printf ("%d", wholebinaryd[i]);
														//}
													int negcount = 0;

													//int poscount = 0;
													int onepos =0;

													//if (flag6 == 1 && flag4 == 1){ //acced
														//printf ("here\n");
														for (int r = 0; r < man; r++){
																						if (decibinary[r] == 1){
																							negcount ++;
																							onepos = r;
																							break;
																						}
																						else if (decibinary[r] == 0){
																							negcount++;
																						}
																					}
																					int gg = 0;
																					//printf ("%d.", decibinary[onepos]);
																					for (int t = onepos+1; t < man+1; t++){
																						printf ("%d", decibinary[t]);
																						gg++;
																					}
																					if (gg < man){
																						while(gg<man){
																							printf("0");
																							gg++;
																						}
																					}
																					//negcount = -1 * negcount;
																					//printf(" %d", negcount);
																					printf("\n");

														//int gg = 0;
														//printf ("%d.", decibinary[onepos]);
														//for (int t = onepos+1; t < man+1; t++){
														//for (int t = 0; t < man; t++){
															//int a = decibinary[t];
															//decbinaryd[t] = a;
															//printf ("%d", decbinaryd[t]);

														//}

														//negcount = -1 * negcount;
														//printf(" %d", negcount);
														//printf("\n");
													//}
													}

													}
													else{
													printf("0");
													printf("0");

													for (int i = 0; i < exp-1; i++){
															printf ("%d", wholebinaryd[i]);
														}
													int negcount = 0;

													//int poscount = 0;
													int onepos =0;

													//if (flag6 == 1 && flag4 == 1){ //acced
														//printf ("here\n");
														for (int r = 0; r < man-1; r++){
																						if (decibinary[r] == 1){
																							negcount ++;
																							onepos = r;
																							break;
																						}
																						else if (decibinary[r] == 0){
																							negcount++;
																						}
																					}
																					int gg = 0;
																					//printf ("%d.", decibinary[onepos]);
																					for (int t = onepos+1; t < man-1; t++){
																						printf ("%d", decibinary[t]);
																						gg++;
																					}
																					if (gg < man-1){
																						while(gg<man-1){
																							printf("0");
																							gg++;
																						}
																					}
																					//negcount = -1 * negcount;
																					//printf(" %d", negcount);
																					printf("\n");	
															}	
													}	
												else if (flag3 == 0){
													if (flag2 == 1){
														printf("0");
														for (int i = 0; i < exp-1; i++){
															printf ("%d", wholebinaryd[i]);
														}
														for (int i = 0; i < man; i++){
															printf ("%d", decibinaryd[i]);
														}
															printf("\n");
													}

													else {
													for (int i = 0; i < exp; i++){
															printf ("%d", wholebinaryd[i]);
														}
													for (int i = 0; i < man; i++){
															printf ("%d", decibinaryd[i]);
														}
													printf("\n");
													}
													}
												else if (flag3 == 1){ //if dec
													if (flag2 == 1){
															//if(dg ==2){
																//printf("00");
															//}
														//printf ("here\n");
														printf("0");
														for (int i = 0; i < exp-1; i++){
															printf ("%d", wholebinaryd[i]);
														}
														//for (int i = 0; i < man; i++){
															//printf ("%d", decibinaryd[i]);
														//}
														//	printf("\n");
													//}

													//else {
													//for (int i = 0; i < exp; i++){
															//printf ("%d", wholebinaryd[i]);
														//}
													int negcount = 0;

													//int poscount = 0;
													int onepos =0;

													//if (flag6 == 1 && flag4 == 1){ //acced
														//printf ("here\n");
														for (int r = 0; r < man; r++){
																						if (decibinary[r] == 1){
																							negcount ++;
																							onepos = r;
																							break;
																						}
																						else if (decibinary[r] == 0){
																							negcount++;
																						}
																					}
																					int gg = 0;
																					//printf ("%d.", decibinary[onepos]);
																					for (int t = onepos+1; t < man+1; t++){
																						printf ("%d", decibinary[t]);
																						gg++;
																					}
																					if (gg < man){
																						while(gg<man){
																							printf("0");
																							gg++;
																						}
																					}
																					//negcount = -1 * negcount;
																					//printf(" %d", negcount);
																					printf("\n");

														//int gg = 0;
														//printf ("%d.", decibinary[onepos]);
														//for (int t = onepos+1; t < man+1; t++){
														//for (int t = 0; t < man; t++){
															//int a = decibinary[t];
															//decbinaryd[t] = a;
															//printf ("%d", decbinaryd[t]);

														//}

														//negcount = -1 * negcount;
														//printf(" %d", negcount);
														//printf("\n");
													//}
													}



							


		}
			free(binary);//frees malloc
							free(wholebinary);
							free(decibinary);
							free(decibinaryd);
							//free(decbinaryd);
							free(wholebinaryd);
}
	}
}









