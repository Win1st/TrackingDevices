<template>
  <div id="app">
    <div class="bg-highlight" style="height: 3vh; width: 100%"></div>

    <div style="height: 150vh">
      <div class="d-flex">
        <div class="flex-fill"></div>

        <div class="flex-fill" style="height: 120vh; width: 90%">
          <div
            class="d-flex flex-row bg-white"
            style="height: 12vh; width: 12vw"
          >
            <img
              :src="require('@/assets/image2.png')"
              style="max-height: 100%; max-width: 100%; border-radius: 80%"
            />

            <div class="ms-3 mt-3" style="height: auto; width: auto">
              <div class="my-0 bd-highlight" style="height: 3vh; width: 100%">
                <div class="fw-bold fs-4 text-dark">
                  {{ this.$cookies.get("account").username }}
                </div>
              </div>
              <div class="mt-1 bd-highlight">
                <div class="fs-5 text-dark" :class="center">
                  {{ this.$cookies.get("account").email }}
                </div>
              </div>
            </div>
          </div>
          <div class="bg-light my-3"></div>

          <div class="d-flex">
            <div
              class="flex-fill bg-highlight"
              style="height: 70vh; width: 90%"
            >
              <div class="bg-highlight" style="height: auto; width: 100%"></div>
              <div
                class="d-flex flex-column bg-white px-0 py-1 border border-secondary border-3"
                style="width: 100%; height: auto; border-radius: 25px"
              >
                <div v-for="(slaves, index) in slavename" :key="index">
                  <div :class="center">
                    <div class="bg-highlight" style="height: auto; width: 90%">
                      <div class="d-flex">
                        <div
                          class="mx-0 px-0 py-0 my-0 mt-2 flex-fill bg-highlight"
                          style="height: auto; width: auto"
                        >
                          
                            <div
                              class="mb-3 mx-0 px-0 mt-0 bg-highlight d-flex align-items-center"
                              style="height: 100%; width: 100%"
                            >
                              <img
                                :src="require('@/assets/image4.png')"
                                style="
                                  max-height: 12vh;
                                  width: auto;
                                  border-radius: 80%;
                                "
                                 @click="History(slaves)"
                              />
                              <div class="d-flex flex-column" style="
                                  max-height: auto;
                                  width: 100%;">
                              <div class="mt-0 ms-4 d-flex flex-column">
                                <div class="my-0 py-0 ms-2 text-dark fs-5">
                                  Tracker's name: {{ slaves.mastername }}
                                </div>
                                <div class="my-0 py-0 ms-2 text-dark fs-5">
                                  Device's name: {{ slaves.slavename }}
                                </div>
                                <div class="my-0 py-0 ms-2 text-dark fs-5">
                                  Status: Online
                                </div>
                                <div class="my-0 py-0 ms-2 text-dark fs-5">
                                  Notify: {{ slaves.notify }}
                                </div>
                                <div class="my-0 py-0 ms-2 text-dark fs-5">
                                  Distance Alerting: {{ slaves.threshold }}
                                </div>
                                <div
                                  class="my-0 py-0 ms-2 mb-0 pb-0 text-dark fs-5"
                                >
                                  Distance = xxxm.
                                </div>
                              </div>
                              <div class="d-flex flex-row px-0 py-0 mx-0 my-0 ms-auto mt-auto">
                                <div
                                  class="bg-highlight mt-auto ms-auto ms-auto mt-auto"
                                  :class="[{ 'bg-secondary': hoverPayment }]"
                                  @mouseover="hoverPayment = true"
                                  @mouseleave="hoverPayment = false"
                                  style="
                                    border: 3px solid white;
                                    border-radius: 5px;
                                    height: auto;
                                    width: 100%;
                                  "
                                  @click="Message(slaves)"
                                >
                                  <div
                                    class="px-3 py-0 btn bg-dark border-dark text-white fw-bold fs-4 border-3 ms-auto mt-auto"
                                    style="
                                      border: 3px solid white;
                                      border-radius: 5px;
                                      height: auto;
                                      width: auto;
                                    "
                                  >
                                    Message
                                  </div>
                                </div>
                                <div
                                  class="bg-highlight mt-auto ms-auto ms-auto mt-auto"
                                  :class="[{ 'bg-secondary': hoverPayment }]"
                                  @mouseover="hoverPayment = true"
                                  @mouseleave="hoverPayment = false"
                                  style="
                                    border: 3px solid white;
                                    border-radius: 5px;
                                    height: auto;
                                    width: 100%;
                                  "
                                  @click="History(slaves)"
                                >
                                  <div
                                    class="px-3 py-0 btn bg-dark border-dark text-white fw-bold fs-4 border-3 ms-auto mt-auto"
                                    style="
                                      border: 3px solid white;
                                      border-radius: 5px;
                                      height: auto;
                                      width: auto;
                                    "
                                  >
                                    History
                                  </div>
                                </div>
                              </div>
                            </div>
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
                  <hr
                    class="mb-0"
                    width="100%;"
                    size="5"
                    color="secondary"
                    noshade
                  />
                </div>
              </div>
            </div>

            <!-- middle-blank -->
            <div class="flex-fill bg-white" style="height: auto; width: 10%">
              <div class="d-flex">
                <div class="flex-fill bg-highlight"></div>
              </div>
            </div>

            <!-- right side -->
            <div
              class="d-flex flex-column bd-highlight"
              style="width: 100%; height: 50%"
            >
              <div class="bg-highlight" style="height: auto; width: 100%"></div>
              <div
                class="d-flex flex-column bg-white px-0 py-1 border border-secondary border-3"
                style="width: 100%; height: 70vh; border-radius: 25px"
              >
                <div :class="center">
                  <div class="bg-highlight" style="height: auto; width: 90%">
                    <div class="d-flex">
                      <div
                        class="mx-0 px-0 py-0 my-0 flex-fill bg-highlight"
                        style="height: auto; width: 90%"
                      >
                        <div
                          request
                          class="mb-3 d-flex mx-0 px-0 mt-3 bg-highlight"
                          style="height: 100%; width: 100%"
                        >
                          <img
                            :src="require('@/assets/image4.png')"
                            style="
                              max-height: 12vh;
                              width: auto;
                              border-radius: 80%;
                            "
                          />
                          <div class="mt-3 ms-1 d-flex flex-column">
                            <div class="my-0 py-0 ms-2 text-dark fw-bold fs-6">
                              {{ selectSlave.slavename }}
                            </div>
                            <div class="my-0 py-0 ms-2 text-dark fs-6">
                              Online
                            </div>
                          </div>
                          <div
                            class="ms-auto"
                            style="
                              width: auto;
                              height: 6vh;
                              border-radius: 25px;
                            "
                          >
                            <router-link
                              to="/profile"
                              :class="center"
                              style="text-decoration: none"
                            >
                              <div
                                class="ms-auto mt-3 btn bg-dark border-dark py-0 text-white fw-bold fs-4 border-3 px-3 btn bg-dark border-dark text-white fw-bold fs-4 border-3"
                                :class="[
                                  center,
                                  { 'bg-secondary': hoverPayment },
                                ]"
                                @mouseover="hoverPayment = true"
                                @mouseleave="hoverPayment = false"
                                style="
                                  border: 3px solid white;
                                  border-radius: 5px;
                                "
                              >
                                Settings
                              </div>
                            </router-link>
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
                <hr
                  class="mt-1"
                  width="100%;"
                  size="5"
                  color="secondary"
                  noshade
                />
                <div
                  class="me-auto mx-3 mt-2 bg-white border border-dark border-3"
                  style="width: auto; height: auto; border-radius: 25px"
                >
                  <div
                    class="mx-3 text-dark fw-bold fs-5 border-3"
                    style="width: 100%; height: auto; border-radius: 25px"
                  >
                    Your device is now out of range.
                  </div>
                </div>
                <div
                  class="me-auto mx-3 mt-2 bg-white border border-dark border-3"
                  style="width: auto; height: auto; border-radius: 25px"
                >
                  <div
                    class="mx-3 text-dark fw-bold fs-5 border-3"
                    style="width: 100%; height: auto; border-radius: 25px"
                  >
                    Your device is now in range.
                  </div>
                </div>
                <div class="mt-auto" :class="center">
                  <div
                    class="mx-3 mt-2 mb-2 bg-white border border-dark border-3"
                    style="width: 35%; height: auto; border-radius: 25px"
                    :class="center"
                  >
                    <div
                      class="my-1 text-dark fw-bold fs-5 border-3"
                      style="width: auto; height: auto; border-radius: 0px"
                      :class="center"
                    >
                      DISTANCES = xxxm.
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
        <div class="flex-fill"></div>
      </div>
    </div>
  </div>
</template>

<script>
// @ is an alias to /src
import axios from "axios";
import { required } from "vuelidate/lib/validators";

export default {
  name: "ProfilePage",
  data() {
    return {
      previousRoutes: [],
      users: [],
      password: "",
      showpassword: false,
      slaves: [],
      selectSlave: "",
      slavename1: "",
      slavename2: "",
      slavename: "",
      threshold: "",
      mastername: "",
      master: "",
      notify: "",
      search: "",
      center: {
        "d-flex": true,
        "justify-content-center": true,
        "align-items-center": true,
      },
      zeros: "px-0 py-0 mx-0 my-0",
    };
  },
  validations: {
    mastername: {
      required: required,
    },
    slavename1: {
      required: required,
    },
    slavename2: {
      required: required,
    },
    threshold: {
      required: required,
    },
    notify: {
      required: required,
    },
    password: {
      required: required,
    },
  },
  mounted() {
    this.getslavename();
  },
  methods: {
    getslavename() {
      axios
        .get("http://localhost:3000/slave", {
          params: {
            search: this.search,
          },
        })
        .then((response) => {
          this.slavename = response.data;
        })
        .catch((err) => {
          console.log(err);
        });
    },

    Adding() {
      this.$v.mastername.$touch();
      this.$v.slavename1.$touch();
      this.$v.password.$touch();
      if (
        !this.$v.mastername.$invalid &&
        !this.$v.slavename1.$invalid &&
        !this.$v.password.$invalid
      ) {
        const data = {
          mastername: this.mastername,
          slavename: this.slavename1,
          username: this.$cookies.get("account").username,
          password: this.password,
        };
        axios
          .post("http://localhost:3000/slaveAdding", data)
          .then(() => {
            alert("Success");
          })
          .catch((err) => {
            alert(err.response.data.details.message);
          });
      }
    },

    Message(slave) {
      this.selectSlave = slave;
    },

    History(slave) {
      this.selectSlave = slave;
    },

    Setting() {
      this.$v.$touch();
      if (!this.$v.$invalid) {
        const data = {
          username: this.username,
          password: this.password,
        };
        axios
          .post("http://localhost:3000/user/login/", data)
          .then((res) => {
            const account = {
              username: res.data.account.username,
              permission: res.data.account.permission,
              firstname: res.data.account.firstname,
              lastname: res.data.account.lastname,
              email: res.data.account.email,
              phone: res.data.account.phone,
            };
            this.$cookies.set("account", account);
            alert("Login Success");
            this.$router.push({ path: "/" });
          })
          .catch((error) => {
            this.error = error.response.data;
          });
      }
    },
  },
  watch: {
    $route(to, from) {
      this.previousRoutes.push(from); // เมื่อมีการเปลี่ยนเส้นทางใหม่ ให้เก็บเส้นทางก่อนหน้าลงในอาร์เรย์
    },
  },
};
</script>
