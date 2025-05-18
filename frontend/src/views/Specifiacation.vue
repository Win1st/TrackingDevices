<template>
  <div id="app">
    <div class="bg-highlight" style="height: 3vh; width: 100%"></div>

    <div style="height: 200vh">
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

            <div class="px-0 py-0 ms-3 mt-3" style="height: auto">
              <div class="my-0 bd-highlight" style="height: 3vh">
                <div class="fw-bold fs-4 text-dark">
                  {{ this.$cookies.get("account").username }}
                </div>
              </div>
              <div class="px-0 py-0 ms-auto mt-1 bd-highlight">
                <div class="ms-auto mx-0 fs-5 text-dark">
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
                              @click="History(slaves) & Clicky(slaves)"
                            />
                            <div
                              class="d-flex flex-column"
                              style="max-height: auto; width: 100%"
                            >
                              <div class="mt-0 ms-4 d-flex flex-column">
                                <div class="my-0 py-0 ms-2 text-dark fs-5">
                                  Tracker's name: {{ slaves.mastername }}
                                </div>
                                <div class="my-0 py-0 ms-2 text-dark fs-5">
                                  Device's name: {{ slaves.slavename }}
                                </div>
                                <!-- <div class="my-0 py-0 ms-2 text-dark fs-5">
                                  Status: Online
                                </div> -->
                                <div class="my-0 py-0 ms-2 text-dark fs-5">
                                  Notification: {{ slaves.notify }}
                                </div>
                                <div class="my-0 py-0 ms-2 text-dark fs-5">
                                  Distance Alerting: {{ slaves.threshold }} m.
                                </div>
                                <div
                                  class="my-0 py-0 ms-2 mb-0 pb-0 text-dark fs-5"
                                >
                                  Distance: {{ distance }} m.
                                </div>
                                <div class="my-0 py-0 ms-2 text-dark fs-5">
                                  <strong>Status:</strong> {{ slaves.statusMessage }}
                                  
                                </div>

                              </div>
                              <div class="mt-2"></div>
                              <div
                                class="d-flex flex-row px-0 py-0 mx-0 my-0 ms-auto mt-auto"
                              >
                                <!-- <div
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
                                  @click="History(slaves) & Clicky(slaves)"
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
                                </div> -->
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
                                  @click="History(slaves) & Clicky(slaves)"
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
                              <!-- {{ Message }} -->
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
                        <div class="d-flex flex-column">
                            <router-link
                              to="/profile"
                              :class="center"
                              style="text-decoration: none"
                            >
                              <div
                                class="ms-auto mt-3 btn bg-dark border-dark py-0 text-white fw-bold fs-4 border-3 px-3 btn border-dark text-white fw-bold fs-4 border-3"
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
                            <div
                                class="mt-3 btn pe-1 bg-danger border-danger py-0 fw-bold border-3 px-3 btn border-danger text-white fs-4"
                                :class="[
                                  center,
                                  { 'bg-danger': hoverPayment },
                                ]"
                                @mouseover="hoverPayment = true"
                                @mouseleave="hoverPayment = false"
                                style="
                                  border: 3px solid white;
                                  border-radius: 5px;
                                  width: auto;
                                "
                              >
                                ALERT <img
                            :src="require('@/assets/image5.png')"
                            style="
                              max-height: 30px;
                              width: 30px;
                            "
                          />
                              </div>
                              </div>
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
              <div v-if="selectSlave.status" class="d-flex flex-row" 
              style="width: 100%; height: auto;">
                <div
                  class="me-auto ms-3 mt-2 bg-white border border-dark border-3"
                  style="width: auto; height: auto; border-radius: 25px"
                >
                  <div
                    class="mx-3 text-dark fw-bold fs-5 border-3"
                    style="width: auto; height: auto; border-radius: 25px"
                  >
                    {{ selectSlave.status }}
                  </div>
                </div>

                <div class="ms-auto me-3 text-dark fs-5"
                    :class="center">
                    {{ formatTimestamp(selectSlave.timestamp) }}
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
                      {{ normaldistance }} m.
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
      normaldistance: 0,
      distance: 0,
      notificationMessage: "",
      currentSlaveThreshold: 0,
      intervalId: null,
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
      timestamp:"",
      search: "",
      message: "Please select slave",
      center: {
        "d-flex": true,
        "justify-content-center": true,
        "align-items-center": true,
      },
      zeros: "px-0 py-0 mx-0 my-0",
      date: new Date(),
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
    this.intervalId = setInterval(this.fetchDistance, 1000);
    this.getSlave();
    this.startInterval();
  },

  beforeUnmount() {
    this.stopInterval();
  },
    
  beforeDestroy() {
    clearInterval(this.intervalId);
  },

  methods: {
    // async fetchDistance() {
    //   try {
    //     const res = await fetch("http://192.168.1.176/distance");
    //     const data = await res.json();
    //     console.log(data);
    //     this.distance = data.distance;
    //   } catch (err) {
    //     console.error("Error fetching distance:", err);
    //   }
    // },

    startInterval() {
      this.intervalID = setInterval(() => {
        this.fetchDistance();
        this.getSlave();
        this.ReHistory();
        //this.Message(); 
      }, 1000);
    },

    // checkDistanceStatus() {
    //   if (!this.selectSlave) return;

    //   const threshold = parseFloat(this.selectSlave.threshold || 0);

    //   if (this.distance > threshold) {
    //     this.notificationMessage = "🚨 Your device is now out of range!";
    //   } else {
    //     this.notificationMessage = "✅ Your device is in range.";
    //   }
    // },

    async fetchDistance() {
      axios
        .get("http://localhost:3000/pulldistance")
        .then((response) => {
          this.distance = response.data.distance;

          // เรียกฟังก์ชันเช็กระยะทันทีหลังได้ข้อมูล
          // this.checkDistanceStatus();
        })
        .catch((err) => {
          console.log(err);
        });
    },

    formatTimestamp(timestamp) {
    if(!timestamp) return " ";
        const date = new Date(timestamp);
        return date.toLocaleString('th-TH');
  },

    getSlave() {
      axios
        .get("http://localhost:3000/userSlave", {
          params: {
            search: this.$cookies.get("account").username,
          },
        })
        .then((response) => {
          const slaves = response.data;

          // คำนวณข้อความสถานะสำหรับแต่ละ slave
          slaves.forEach((slave) => {
            const threshold = parseFloat(slave.threshold);
            const currentDistance = parseFloat(this.distance);

            if (!isNaN(threshold) && !isNaN(currentDistance)) {
              slave.statusMessage =
                currentDistance < threshold
                  ? "✅ Your device is in range."
                  : "🚨 Your device is now out of range!";
            } else {
              slave.statusMessage = "❓ Unknown status";
            }
          });

          this.slavename = slaves;
        })
        .catch((err) => {
          console.log(err);
        });
    },

    Clicky(slave) {
      this.selectSlave = slave;
    },

    // Message() {
    //   if (this.selectSlave && this.selectSlave.slavename) {
    //   const data = {
    //     slavename: this.selectSlave.slavename,
    //   };
    //   console.log(data)
    //   axios
    //     .post("http://localhost:3000/pulldistance", data)
    //     .then((res) => {
    //       this.message = res.data.slave.status;

    //     })
    //     .catch(() => {
    //       alert("ERROR");
    //     });
    //   }
    // },

    History(slave) {
      this.selectSlave = slave;
      console.log("ab");
      const data = {
        slavename: slave.slavename,
      };
      axios
        .post("http://localhost:3000/slaveDistance", data)
        .then((res) => {
          this.message = res.data.slave.status;
        })
      
      axios
        .get("http://localhost:3000/pulldistance")
        .then((response) => {
          this.normaldistance = response.data.distance;
        })

        .catch(() => {
          alert("ERROR");
        });
    },

    ReHistory() {
      if(this.selectSlave){
          const data = {
          slavename:  this.selectSlave.slavename,
        };
        axios
          .post("http://localhost:3000/slaveDistance", data)
          .then((res) => {
            this.message = res.data.slave.status;
            this.selectSlave = res.data.slave;
            console.log(res)
          })
        
        axios
          .get("http://localhost:3000/pulldistance")
          .then((response) => {
            this.normaldistance = response.data.distance;
          })

          .catch(() => {
            alert("ERROR");
          });
      }
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

  computed: {
    
  },

  watch: {
    message(newValue, oldValue) {
        if(newValue != oldValue){
          alert(newValue)} 
    },
    
    
    $route(to, from) {
      this.previousRoutes.push(from); // เมื่อมีการเปลี่ยนเส้นทางใหม่ ให้เก็บเส้นทางก่อนหน้าลงในอาร์เรย์
    },
  },
};

document
  .getElementById("alert-btn")
  .addEventListener("click", async () => {
    try {
      let res = await fetch("/alert", { method: "POST" });
      if (!res.ok) throw new Error("Network error");
      console.log("Alert triggered");
    } catch(e) {
      console.error(e);
    }
  });
  
</script>